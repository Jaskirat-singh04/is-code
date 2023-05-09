#include <bits/stdc++.h>
using namespace std;

int key[4] = {2, 0, 1, 3};

// Encryption
string encryptMessage(string msg)
{
    int row, col, j;
    string cipher = "";

    /* calculate column of the matrix*/
    col = 4;

    /* calculate Maximum row of the matrix*/
    row = msg.length() / col;

    if (msg.length() % col)
        row += 1;

    char matrix[row][col];

    for (int i = 0, k = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (msg[k] == '\0')
                matrix[i][j] = '\n';
            else
                matrix[i][j] = msg[k];
            k++;
        }
    }

    for (int j = 0; j < col; j++)
    {
        int x;
        for (int k = 0; k < col; k++)
        {
            if (j == key[k])
                x = k;
        }

        // getting cipher text from matrix column wise using permuted key
        for (int i = 0; i < row; i++)
        {
            if (matrix[i][x] != '\n')
                cipher += matrix[i][x];
        }
    }

    return cipher;
}

// Decryption
string decryptMessage(string cipher)
{
    /* calculate row and column for cipher Matrix */
    int col = 4;

    int row = cipher.length() / col;
    if (cipher.length() % col)
        row += 1;

    char cipherMat[row][col];

    /* add character into matrix column wise */
    for (int j = 0, k = 0; j < col; j++)
        for (int i = 0; i < row; i++)
            cipherMat[i][j] = cipher[k++];

    /* Arrange the matrix column wise according
    to permutation order by adding into new matrix */
    char decCipher[row][col];

    int k = 0;
    for (int j = 0; j < col; j++, k++)
    {
        for (int i = 0; i < row; i++)
        {
            decCipher[i][k] = cipherMat[i][key[j]];
        }
    }

    /* getting Message using matrix */
    string msg = "";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (decCipher[i][j] != '\n')
                msg += decCipher[i][j];
        }
    }
    return msg;
}

// Driver Program
int main(void)
{
    /* message */
    string msg = "transposition technique";

    // Calling encryption function
    string cipher = encryptMessage(msg);
    cout << "Encrypted Message: " << cipher << endl;

    // Calling Decryption function
    cout << "Decrypted Message: " << decryptMessage(cipher) << endl;

    return 0;
}
