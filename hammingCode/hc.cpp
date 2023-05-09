#include <bits/stdc++.h>
using namespace std;

class hamming
{
    string data;  // raw data
    int m, r = 0; // m is the length of raw data and r is the number of redundant bits
    char *msg;    // it will store the all bits (data + redundant).

public:
    hamming()
    {

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

        data = lines[random_number];

        cout << "Data... " << data << endl;
        m = data.size();

        int power = 1;
        // finding the number of redundant bits
        // These redundant bits are placed at positions that correspond to the power of 2.
        while (power < (m + r + 1))
        {
            r++;
            power *= 2;
        }

        msg = new char[m + r + 1];
        int curr = 0;

        // initializing the msg with data bits and for redundant bits, an initial value of x
        for (int i = 1; i <= m + r; i++)
        {
            if (i & (i - 1))
            {
                msg[i] = data[curr++];
            }
            else
                msg[i] = 'x';
        }

        setRedundantBits();
    }

    void setRedundantBits()
    {

        // R1 bit is calculated using parity check at all the bits positions whose binary representation includes a 1 in the least significant position.
        // R2 bit is calculated using parity check at all the bits positions whose binary representation includes a 1 in the second position from the least significant bit.
        // R4 bit is calculated using parity check at all the bits positions whose binary representation includes a 1 in the third position from the least significant bit and so on.

        int bit = 0;
        // outer loop runs for redundant bits (1 ,2 ,4 ,8 ....)
        for (int i = 1; i <= m + r; i *= 2)
        {
            int count = 0;
            // inner loop runs for data bits
            for (int j = i + 1; j <= m + r; j++)
            {
                if (j & (1 << bit))
                {
                    if (msg[j] == '1')
                        count++;
                }
            }

            if (count & 1)
                msg[i] = '1';
            else
                msg[i] = '0';

            bit++;
        }

        message();
    }

    void message()
    {
        cout << "The data packet to be sent is : ";
        for (int i = 1; i <= (m + r); i++)
        {
            cout << msg[i] << " ";
        }
        cout << endl;

        msg[3] == '0' ? msg[3] = '1' : msg[3] = '0';
        receiver();
    }

    void receiver()
    {

        cout << "Received data packet : ";
        for (int i = 1; i <= (m + r); i++)
        {
            cout << msg[i] << " ";
        }
        cout << endl;

        // this ans will store the redundant bits, if they were right then according to even parity they will store 0 else if some error was made in a bit it will store 1
        string ans = "";
        int bit = 0;

        for (int i = 1; i <= m + r; i *= 2)
        {
            int count = 0;
            for (int j = i + 1; j <= m + r; j++)
            {
                if (j & (1 << bit))
                {
                    if (msg[j] == '1')
                        count++;
                }
            }

            if (count & 1)
            {
                if (msg[i] == '1')
                    ans.push_back('0');
                else
                    ans.push_back('1');
            }
            else
            {
                if (msg[i] == '0')
                    ans.push_back('0');
                else
                    ans.push_back('1');
            }
            bit++;
        }
        // if the ans had any occurrence of 1 then there is some fault
        if (ans.find('1') != string::npos)
        {
            int power = 1;
            int wrongbit = 0;

            for (int i = 0; i < ans.size(); i++)
            {
                if (ans[i] == '1')
                    wrongbit += power;
                power *= 2;
            }
            cout << "bit number " << wrongbit << " is wrong." << endl;

            msg[wrongbit] == '0' ? msg[wrongbit] = '1' : msg[wrongbit] = '0';
        }
        // if the ans dont have any occurrence of 1 then it is correct
        else
        {
            cout << "correct data packet received " << endl;
        }

        display();
    }

    void display()
    {
        cout << "\nCorrect message... ";
        for (int i = 1; i <= m + r; i++)
        {
            if (i & (i - 1))
            {
                cout << msg[i] << " ";
            }
        }
    }
};
int main()
{
    hamming h;
    return 0;
}