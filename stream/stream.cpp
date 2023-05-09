#include <bits/stdc++.h>
using namespace std;

int main()
{
    string message = "autokeyedvigenereCipher";
    string msg = message;
    transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
    int msgLen = msg.length();

    string key = "stream";
    transform(key.begin(), key.end(), key.begin(), ::toupper);
    int keyLen = key.length();

    char newKey[msgLen], encryptedMsg[msgLen], decryptedMsg[msgLen];

    // generating new key
    for (int i = 0, j = 0; i < msgLen; ++i, ++j)
    {
        if (j == keyLen)
            break;

        newKey[i] = key[j];
    }

    for (int i = keyLen, j = 0; i < msgLen; ++i, ++j)
    {
        newKey[i] = msg[j];
    }

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