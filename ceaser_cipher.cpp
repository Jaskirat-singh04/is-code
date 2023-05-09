#include <iostream>
using namespace std;
string encrypt(string text, int s)
{
	string cipher = "";
	for (int i = 0; i < text.length(); i++)
	 {

		if (isupper(text[i]))
			cipher += char(int(text[i] + s - 65) % 26 + 65);

		else
			cipher += char(int(text[i] + s - 97) % 26 + 97);
	 }
	return cipher;
}
string decrpyt(string text, int s)
{
	string cipher = "";
	for (int i = 0; i < text.length(); i++)
	 {

		if (isupper(text[i]))
			cipher += char(int(text[i] - s - 65) % 26 + 65);

		else
			cipher += char(int(text[i] - s - 97) % 26 + 97);
	 }
	return cipher;
}

int main()
{
	string text ;
	cout<<"Enter the plain text\n";
	cin>>text;
	int s;
	cout<<"Enter the key length\n";
	cin>>s;
	cout << "Text : " << text;
	cout << "\nKey: " << s;
	cout << "\nCipher: " << encrypt(text, s);
    cout<<"\nDecrpytText:"<<decrpyt(encrypt(text, s),s);
	return 0;
}