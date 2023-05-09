#include <bits/stdc++.h>
using namespace std;

int main()
{
    string message = "vernamCipher";
    string msg = message;
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    int msgLen = msg.length();

    string key = "helloworlddd";
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    int keyLen = key.length();

    // length of msg and key should be equal
    if (msgLen != keyLen)
        exit(101);

    char encryptedMsg[msgLen], decryptedMsg[msgLen];
    encryptedMsg[msgLen] = '\0'; // add null-termination
    decryptedMsg[msgLen] = '\0'; // add null-termination

    // encryption
    for (int i = 0; i < msgLen; ++i)
    {
        int m = msg[i];
        m -= 65;
        int k = key[i];
        k -= 65;
        encryptedMsg[i] = ((m ^ k) % 26) + 'A';
    }

    // decryption
   for (int i = 0; i < msgLen; ++i)
{
    int m = encryptedMsg[i];
    m -= 65;
    int k = key[i];
    k -= 65;
    decryptedMsg[i] = ((m ^ k) % 26) + 'A';
}


    cout << "\nOriginal Message: " << message;
    cout << "\nKey: " << key;
    cout << "\nEncrypted Message: " << encryptedMsg;
    cout << "\nDecrypted Message: " << decryptedMsg << "\n\n\n";

    return 0;
}