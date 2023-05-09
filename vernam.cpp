#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

string prepare_input(string input) {
string prepared_input = "";
for (char& c : input) {
if (isalpha(c)) {
prepared_input += toupper(c);
}
}
return prepared_input;
}

string generate_key(int length) {
string key = "";
for (int i = 0; i < length; i++) {
key += (char)('A' + rand() % 26);
}
return key;
}

string encrypt(string plaintext, string key) {
string prepared_plaintext = prepare_input(plaintext);
string encrypted_text = "";
for (int i = 0; i < prepared_plaintext.length(); i++) {
int plaintext_bit = prepared_plaintext[i] - 'A';
int key_bit = key[i] - 'A';
int encrypted_bit = plaintext_bit ^ key_bit;
encrypted_text += (char)('A' + encrypted_bit);
}
return encrypted_text;
}

string decrypt(string ciphertext, string key) {
string decrypted_text = "";
for (int i = 0; i < ciphertext.length(); i++) {
int ciphertext_bit = ciphertext[i] - 'A';
int key_bit = key[i] - 'A';
int decrypted_bit = ciphertext_bit ^ key_bit;
decrypted_text += (char)('A' + decrypted_bit);
}
return decrypted_text;
}

int main() {
string plaintext = "the quick brown fox jumps over the lazy dog";
string key = generate_key(plaintext.length());
string ciphertext = encrypt(plaintext, key);
cout << "Ciphertext: " << ciphertext << endl;
string decrypted_plaintext = decrypt(ciphertext, key);
cout << "Decrypted plaintext: " << decrypted_plaintext << endl;
return 0;
}