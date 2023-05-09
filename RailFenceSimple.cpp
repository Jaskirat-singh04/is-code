#include <iostream>
 
using namespace std;
 
string encrypt(string msg, int key)
{
    int n = msg.length();
    char matrix[key][n];
    string enctext = "";
 
    for (int i = 0; i<key; i++)
    {
        for (int j = 0; j<n; j++)
        {
            matrix[i][j] = '!';
        }
    }
 
    for (int i = 0; i<key; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
 
    int j = 0;
    int i = 0;
 
    while(i<n)
    {
        if (j<key)
        {
            while(j<key)
            {
                cout<<msg[i]<<" -> "<<' '<<"("<<j<<" , "<<i<<")"<<endl;
                matrix[j][i] = msg[i];
                j++;
                i++;
            }
            cout<<endl;
        }
 
        else
        {
            j = key-2;
 
            while(j>0)
            {
                cout<<msg[i]<<" -> "<<' '<<"("<<j<<" , "<<i<<")"<<endl;
                matrix[j][i] = msg[i];
                j--;
                i++;
                cout<<endl;
            }
        }
 
    }
 
    cout<<endl;
 
    for (int i = 0; i<key; i++)
    {
        for (int j = 0; j<n; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
 
 
    for (int i = 0; i<key; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (matrix[i][j] != '!')
            enctext.push_back(matrix[i][j]);
        }
        cout<<endl;
    }
 
    return enctext;
 
}
 
// char** retmatrix(string msg, int key)
// {
//     int n = msg.length();
//     char** matrix;
//     string enctext = "";
 
//     for (int i = 0; i<key; i++)
//     {
//         for (int j = 0; j<n; j++)
//         {
//             matrix[i][j] = '!';
//         }
//     }
 
//     int j = 0;
//     int i = 0;
 
//     while(i<n)
//     {
//         if (j<key)
//         {
//             while(j<key)
//             {
//                 matrix[j][i] = msg[i];
//                 j++;
//                 i++;
//             }
//             cout<<endl;
//         }
 
//         else
//         {
//             j = key-2;
 
//             while(j>0)
//             {
//                 matrix[j][i] = msg[i];
//                 j--;
//                 i++;
//                 cout<<endl;
//             }
//         }
 
//     }
 
 
 
//     for (int i = 0; i<key; i++)
//     {
//         for (int j = 0; j<n; j++)
//         {
//             if (matrix[i][j] != '!')
//             enctext.push_back(matrix[i][j]);
//         }
//         cout<<endl;
//     }
 
//     return matrix;
 
// }
 
// void decrypt(char **met,string msg, int key)
// {
//     cout<<"Decrypted text: ";
//     int n = msg.length();
//     char matrix[key][n];
//     string dectext = "";
 
//     int j = 0;
//     int i = 0;
 
//     while(i<n)
//     {
//         if (j<key)
//         {
//             while(j<key)
//             {
//                 cout<<met[j][i];
//                 j++;
//                 i++;
//             }
//             cout<<endl;
//         }
 
//         else
//         {
//             j = key-2;
 
//             while(j>0)
//             {
//                 cout<<met[j][i];
//                 j--;
//                 i++;
//                 cout<<endl;
//             }
//         }
 
//     }
// }
 
int main() 
{
 
	string str;
    int k;
 
	cout<<"Enter the text to be encrypted: ";
	cin>>str;
 
    int n;
    n = str.length();
 
    cout<<"Enter the length of the key: ";
    cin>>k;
 
    string enc = encrypt(str, k);
    cout<<"Ecrypted Text: "<<enc<<endl;
 
    // cout<<"Test";
    // char **met;
    // met  = retmatrix(str, k);
 
 
    // decrypt(met, str, k);
}