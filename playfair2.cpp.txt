#include <iostream>
#include <string>
using namespace std;

string removeSpaces(string input);
void encrypt(string pt, string key);
char **createMatrix(string key);
void search(char **matrix, char a, char b, int arr[]);
int mod5(int a);
string prepare(string input);
string toLowerCase(string input);

int main()
{
    cout << "Enter the text to be encrypted \n";
    string input, key;
    getline(cin, input);
    cout << "Enter the key \n";
    getline(cin, key);
    input = removeSpaces(input);
    input = toLowerCase(input);
    key = toLowerCase(key);
    cout << "Key in lower case: " << key << endl;
    input = prepare(input);
    cout << "Prepared input : " << input << endl;
    encrypt(input, key);
}

string toLowerCase(string input)
{
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            char c = char(input[i] + 32);
            output.push_back(c);
        }
        else
            output.push_back(input[i]);
    }
    return output;
}

string removeSpaces(string input)
{
    string output;
    int index = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
            output.push_back(input[i]);
    }
    return output;
}

void encrypt(string pt, string key)
{
    string output = "";
    char **matrix;
    matrix = createMatrix(key);
    int a[4];

    for (int i = 0; i < pt.length(); i += 2)
    {

        search(matrix, pt[i], pt[i + 1], a);

        if (a[0] == a[2])
        {
            output[i] = matrix[a[0]][mod5(a[1] + 1)];
            output[i + 1] = matrix[a[0]][mod5(a[3] + 1)];
        }
        else if (a[1] == a[3])
        {
            output[i] = matrix[mod5(a[0] + 1)][a[1]];
            output[i + 1] = matrix[mod5(a[2] + 1)][a[1]];
        }
        else
        {
            output[i] = matrix[a[0]][a[3]];
            output[i + 1] = matrix[a[2]][a[1]];
        }
    }
    cout << "Encrypted text : ";
    for (int i = 0; i < pt.length(); i++)
        cout << output[i];
}

char **createMatrix(string key)
{
    char **matrix = new char *[5];
    for (int i = 0; i < 5; i++)
        matrix[i] = new char[5];
    key = key + "abcdefghiklmnopqrstuvwxyz";
    bool used[26];
    for (int i = 0; i < 26; i++)
        used[i] = false;
    int i = 0;
    int j = 0;
    for (int index = 0; index < key.length(); index++)
    {
        int c = (int)(key[index] - 97);
        if (used[c] == false)
        {
            matrix[i][j++] = key[index];
            used[c] = true;
        }
        if (j == 5)
        {
            i++;
            j = 0;
        }
    }
    cout << "Matrix : \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return matrix;
}

// arr[0], arr[1] - position of a
// arr[2], arr[3] - position of b
void search(char **matrix, char a, char b, int arr[])
{
    int i, j;
    if (a == 'j')
        a = 'i';
    else if (b == 'j')
        b = 'i';
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == a)
            {
                arr[0] = i;
                arr[1] = j;
            }
            else if (matrix[i][j] == b)
            {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// calculates mod 5
int mod5(int a) { return (a % 5); }

// prepare the input to make its length to be even
string prepare(string input)
{
    string predparedInput = "";
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input[i] == input[i + 1])
        {
            predparedInput.push_back(input[i]);
            predparedInput.push_back('x');
        }
        else
            predparedInput.push_back(input[i]);
    }
    if (predparedInput.length() % 2 != 0)
    {
        predparedInput.push_back('z');
    }
    return predparedInput;
}