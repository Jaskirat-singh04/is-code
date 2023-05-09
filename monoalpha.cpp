#include <iostream>
using namespace std;

string Monoalphabetic_Cipher_encryption(string message)
{
    int n = message.length();
    int temp;

    string key = "FDSAVCXZGHJKLREWQTYUIOPMNB";

    string enctext = " ";

    for (int i = 0; i < n; i++)
    {
        temp = message[i] - 'a';
        enctext += key[temp];
    }

    return enctext;
}

string Monoalphabetic_Cipher_decryption(string message)
{
    int n = message.length();
    int temp;

    string key = "dzfboaijuklmxyvwqncrtepgsh";
    string dectext = "";
    for (int i = 0; i < n; ++i)
    {
        temp = message[i] - 'A';
        dectext += key[temp];
    }
    return dectext;
}
int main()
{
    string s;
    cout << "Enter Message: ";
    getline(cin, s);

    string p = Monoalphabetic_Cipher_encryption(s);

    cout << "Encrypted Text is :" << p << "\n";

    cout << "Decrypted text is: " << Monoalphabetic_Cipher_decryption(p) << "\n";

    system("pause");
    return 0;
}