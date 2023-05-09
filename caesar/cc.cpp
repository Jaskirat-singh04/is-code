#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout << "Enter the message:\n";
    string msg;
    cin >> msg; // take the message as input
    int i, j, length, choice, key;
    cout << "Enter key: ";
    cin >> key; // take the key as input
    length = msg.size();
    char ch;

    for (int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        // encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        // encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }

    cout << "Encrypted message: " << msg << endl;

    // for decryption
    for (int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        // decrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch - key;
            if (ch < 'a')
            {
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        // decrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch - key;
            if (ch < 'A')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
    }
    cout << "Decrypted message: " << msg << endl;
}
