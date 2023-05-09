#include <bits/stdc++.h>
using namespace std;

string encryption(string message)
{
    int n = message.length(), temp;
    string key = "FDSAVCXZGHJKLREWQTYUIOPMNB";
    string ency = "";
    for (int i = 0; i < n; ++i)
    {
        temp = message[i] - 'A';
        ency += key[temp];
    }
    return ency;
}

string decryption(string message)
{
    int n = message.length(), temp;
    string key = "DZFBOAIJUKLMXYVWQNCRTEPGSH";
    string ency = "";
    for (int i = 0; i < n; ++i)
    {
        temp = message[i] - 'A';
        ency += key[temp];
    }
    return ency;
}
int main()
{
    string msg = "monoalphabetic";
    cout << "\nOriginal Message: " << msg << endl;
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    string p = encryption(msg);
    cout << "encryption :" << p << "\n";
    cout << "decryption: " << decryption(p) << "\n";
    system("pause");
    return 0;
}