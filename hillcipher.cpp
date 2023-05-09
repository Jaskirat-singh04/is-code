// C++ code to implement Hill Cipher
#include <iostream>
using namespace std;

void generateKeyMatrix(string key, int keyMatrix[][3]);
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]);
void HillCipher(string message, string key);


// Driver function for above code
int main()
{
    // Get the message to be encrypted
    string message = "ACT";

    // Get the key
    string key = "GYBNQKURP";

    HillCipher(message, key);

    return 0;
}

// Following function generates the
// key matrix for the key string
void generateKeyMatrix(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }

    cout<<"keymatrix: \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<keyMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Following function encrypts the message
void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1])
{
    int x, i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++)
            {
                cipherMatrix[i][j] +=
                    keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }

    cout<<"Ciphertext(Numeric): \n";
    for (j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++)
            {
                cout<<cipherMatrix[j][x]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
}

// Function to implement Hill Cipher
void HillCipher(string message, string key)
{
    // Get key matrix from the key string
    int keyMatrix[3][3];
    generateKeyMatrix(key, keyMatrix);

    int messageVector[3][1];

    // Generate vector for the message
    for (int i = 0; i < 3; i++)
    {
        messageVector[i][0] = (message[i]) % 65;
    }

    cout<<"Message Vector: \n";
    for (int i = 0; i < 3; i++)
    {
        cout<<messageVector[i][0]<<" ";
    }
    cout<<endl;
    cout<<endl;

    int cipherMatrix[3][1];

    // Following function generates
    // the encrypted vector
    encrypt(cipherMatrix, keyMatrix, messageVector);

    string CipherText;

    // Generate the encrypted text from
    // the encrypted vector
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;

    // Finally print the ciphertext
    cout << " Ciphertext:" << CipherText;
}