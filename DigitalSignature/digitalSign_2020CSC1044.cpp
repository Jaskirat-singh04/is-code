#include <bits/stdc++.h>
using namespace std;

bool prime(int x);
int gcd(int a, int b);
int publickey(int phi);
int privatekey(int e, int phi);
int encrypt(int m, int e, int n);
void decrypt(int len, int C[], int d, int n);

int main()
{
    // 2 random prime numbers
    int p = 13;
    int q = 11;

    if (!prime(p) || !prime(q))
    {
        cout << "\nERROR";
        exit(101);
    }

    // MESSAGE
    string msg = "saloni ghgfn hfg ";
    cout << "\nMESSAGE : " << msg;
    int len = msg.length();

    int M[len];
    for (int i = 0; i < len; i++)
    {
        M[i] = msg[i];
    }

    // cout << "\nASCII message : ";
    // for (int i = 0; i < len; i++)
    // {
    //     cout << M[i] << " ";
    // }

    int n = p * q; // calculate n
    cout << "\nn : " << n;

    int phi = (p - 1) * (q - 1); // calculate phi
    cout << "\nphi : " << phi;

    // public key (e stands for encrypt)
    int e = publickey(phi);
    cout << "\ne : " << e;

    // private key (d stands for decrypt)
    int d = privatekey(e, phi);
    cout << "\nd : " << d;

    // encrypt the message
    cout << "\nTHE ENCRYPTED MESSAGE IS : ";
    int C[len];
    for (int i = 0; i < len; i++)
    {
        C[i] = encrypt(M[i], e, n);
        cout << C[i];
    }

    // decrypt the message
    decrypt(len, C, d, n);
}

bool prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

// find gcd
int gcd(int a, int b)
{
    int t;
    while (1)
    {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int publickey(int phi)
{
    int e = 7;
    if (!prime(e))
    {
        cout << "\nERROR";
        exit(101);
    }
    int track;
    // for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while (e < phi)
    {
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }

    return e;
}

int privatekey(int e, int phi)
{
    // choosing d such that it satisfies d*e = 1 mod phi
    // double d1 = 1.0 / e;
    // double d = fmod(d1, phi);

    // Extended Euclidean Algorithm
    // int ee[2][2];

    // ee[0][0] = ee[0][1] = phi;
    // ee[1][0] = e;
    // ee[1][1] = 1;

    // int x, y;

    // while (ee[1][0] > 1)
    // {
    //     x = fmod(ee[0][0], ee[1][0]);
    //     x = x * ee[1][0];
    //     x = ee[0][0] - x;

    //     y = fmod(ee[0][0], ee[1][0]) * ee[1][1];
    //     y = ee[0][1] - y;
    //     y = fmod(y, phi);
    // }

    // int d = ee[1][1];

    int k = 1;
    while (1)
    {
        k = k + phi;
        if (k % e == 0)
            return (k / e);
    }

    // return d;
}

int encrypt(int m, int e, int n)
{
    // double y = pow(m, e);
    // y = fmod(y, n);

    int k = 1;
    for (int j = 0; j < e; j++)
    {
        k = k * m;
        k = k % n;
    }

    return k;
}

void decrypt(int len, int C[], int d, int n)
{
    char m[len];
    double x;

    cout << "\nTHE DECRYPTED MESSAGE IS : ";
    for (int i = 0; i < len; i++)
    {

        // x = pow(C[i], d);
        // x = fmod(x, n);
        // m[i] = char(x);

        int k = 1;
        for (int j = 0; j < d; j++)
        {
            k = k * C[i];
            k = k % n;
        }
        m[i] = char(k);

        cout << m[i];
    }
    cout << endl;
}