#include <bits/stdc++.h>
using namespace std;

class ssyndrome
{
    int n, k;
    bool *u;  // message
    bool **p; // p matrix
    bool **G; // generator matrix
    bool *v;  // code word
    bool **H; // parity check matrix
    bool *r;  // received code word
    bool *e;  // error
    bool *s;  // syndrome

    ofstream of;
    ofstream off;

public:
    ssyndrome() {}
    ~ssyndrome();
    void input();
    void genmat();
    void message();
    void codeword();
    void paritymat();
    void syndrome();
};

ssyndrome::~ssyndrome()
{
    for (int i = 0; i < k; i++)
    {
        delete[] p[i];
        delete[] G[i];
    }

    for (int i = 0; i < (n - k); i++)
    {
        delete[] H[i];
    }

    delete[] p;
    delete[] G;
    delete[] u;
    delete[] v;
    delete[] r;
    delete[] e;
    delete[] s;
}

void ssyndrome::input()
{
    cout << "\nEnter number of bits in code word... ";
    cin >> n;
    cout << "\nEnter number of bits in message... ";
    cin >> k;

    p = new bool *[k];
    cout << "\nEnter " << (n - k) * k << " elements of p matrix... ";
    for (int i = 0; i < k; i++)
    {
        p[i] = new bool[n - k];
        for (int j = 0; j < (n - k); j++)
        {
            cin >> p[i][j];
        }
    }
}

void ssyndrome::genmat()
{
    // identity matrix (kxk)
    bool ind[k][k];
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i == j)
            {
                ind[i][j] = 1;
            }
            else
            {
                ind[i][j] = 0;
            }
        }
    }

    // generator matrix
    G = new bool *[k];

    // concatenate identity matrix with p matrix
    for (int i = 0; i < k; i++)
    {
        G[i] = new bool[n];
        for (int j = 0; j < (n - k); j++)
        {
            G[i][j] = p[i][j];
            G[i][j + (n - k)] = ind[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 2 * (n - k), l = (n - k); j < n, l < k; j++, l++)
        {
            G[i][j] = ind[i][l];
        }
    }

    cout << "\nGenerator Matrix... \n";
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
}

void ssyndrome::paritymat()
{
    // identity matrix ((n-k)x(n-k))
    bool ind[n - k][n - k];
    for (int i = 0; i < (n - k); i++)
    {
        for (int j = 0; j < (n - k); j++)
        {
            if (i == j)
            {
                ind[i][j] = 1;
            }
            else
            {
                ind[i][j] = 0;
            }
        }
    }

    // tranpose of p matrix
    bool T[n - k][k];
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < (n - k); ++j)
        {
            T[j][i] = p[i][j];
        }
    }

    // parity check matrix
    H = new bool *[n - k];

    // concatenate identity matrix with transpose of p matrix
    for (int i = 0; i < n - k; i++)
    {
        H[i] = new bool[n];
        for (int j = 0; j < (n - k); j++)
        {
            H[i][j] = ind[i][j];
            H[i][j + (n - k)] = T[i][j];
        }
    }
    for (int i = 0; i < (n - k); i++)
    {
        for (int j = 2 * (n - k), l = (n - k); j < n, l < k; j++, l++)
        {
            H[i][j] = T[i][l];
        }
    }

    cout << "\nParity Check Matrix... \n";
    for (int i = 0; i < (n - k); i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << H[i][j] << " ";
        }
        cout << endl;
    }
}

void ssyndrome::message()
{
    u = new bool[k];
    for (int i = 0; i < k; i++)
    {
        u[i] = 0;
    }

    of.open("msgs.txt", ios::app);
    off.open("codewords.txt", ios::app);

    for (int i = 0; i < pow(2, k); i++)
    {
        int x = i;

        cout << "\nMessage : ";
        for (int j = k - 1; x > 0; j--)
        {
            u[j] = x % 2;
            x = x / 2;
        }

        for (int j = 0; j < k; j++)
        {
            cout << u[j];
            of << u[j];
        }
        of << "\n";

        codeword();
        for (int j = 0; j < k; j++)
        {
            u[j] = 0;
        }
    }
    of.close();
    off.close();
    return;
}

void ssyndrome::codeword()
{
    v = new bool[n];

    cout << "\nCode word... ";

    // v = u.G
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            v[i] = (v[i] + (u[j] * G[j][i])) % 2;
        }

        cout << v[i];
        off << v[i];
    }

    cout << endl;
    off << "\n";
    return;
}

void ssyndrome::syndrome()
{
    // received code word
    r = new bool[n];

    // error
    e = new bool[n];

    bool x = 0;

    string line;
    vector<string> lines;

    srand(time(0));

    // input file stream
    ifstream file("codewords.txt");

    // count number of total lines in the file and store the lines in the string vector
    int total_lines = 0;
    while (getline(file, line))
    {
        total_lines++;
        lines.push_back(line);
    }

    // generate a random number between 0 and count of total lines
    int random_number = rand() % total_lines;

    // fetch the line where line index (starting from 0) matches with the random number

    string recv = lines[random_number];

    cout << "\nReceived codeword... ";
    for (int i = 0; i < n; i++)
    {
        if (recv[i] == '0')
            r[i] = 0;
        else
            r[i] = 1;
        cout << r[i];

        // e[i] = (r[i] + v[i]) % 2;
        // if (e[i] == 1)
        // {
        //     x = 1;
        // }
    }

    // transpose of parity check matrix
    bool T[n][n - k];
    for (int i = 0; i < (n - k); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            T[j][i] = H[i][j];
        }
    }

    // syndrome
    s = new bool[n - k];
    cout << "\nSyndrome... ";

    // s = r.H(transpose)
    for (int i = 0; i < (n - k); i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i] = (s[i] + (r[j] * T[j][i])) % 2;
        }

        cout << s[i] << " ";
        if (s[i] == 1)
            x = 1;
    }

    if (s)
    {
        cout << "\nError in received code word...";
    }
    else
    {
        cout << "\nThere might be an error in received code word...";
    }

    cout << endl;
}

int main()
{
    ssyndrome s1;
    s1.input();
    s1.genmat();
    s1.paritymat();
    s1.message();
    s1.syndrome();

    return 0;
}