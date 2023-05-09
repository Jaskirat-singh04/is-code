#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    string message = "vigenereCipher";
    string msg = message;
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    int msgLen = msg.length();

    string key = "HELLO";
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    int keyLen = key.length();

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    // generating new key
    for (int i = 0, j = 0; i < msgLen; ++i, ++j)
    {
        if (j == keyLen)
            j = 0;

        newKey[i] = key[j];

    }

    newKey[msgLen] = '\0'; // add null-termination
    encryptedMsg[msgLen] = '\0'; // add null-termination
    decryptedMsg[msgLen] = '\0'; // add null-termination

    // encryption
    for (int i = 0; i < msgLen; ++i)
    {
        encryptedMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
    }

    // decryption
    for (int i = 0; i < msgLen; ++i)
    {
        decryptedMsg[i] = (((encryptedMsg[i] - newKey[i]) + 26) % 26) + 'A';
    }

    cout << "\nOriginal Message: " << message;
    cout << "\nKey: " << key;
    cout << "\nNew Generated Key: " << newKey;
    cout << "\nEncrypted Message: " << encryptedMsg;
    cout << "\nDecrypted Message: " << decryptedMsg << "\n\n\n";

    return 0;
}