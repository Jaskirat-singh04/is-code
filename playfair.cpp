#include <iostream>
#include <string>
#include <algorithm>

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

string generate_key(string key) {
    string generated_key = "";
    for (char& c : key) {
        if (isalpha(c)) {
            generated_key += toupper(c);
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') {
            continue;
        }
        if (generated_key.find(c) == string::npos) {
            generated_key += c;
        }
    }
    return generated_key;
}

void generate_table(string key, char table[5][5]) {
    string generated_key = generate_key(key);
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            table[i][j] = generated_key[k];
            k++;
        }
    }
}

void find_position(char table[5][5], char letter, int& row, int& col) {
    if (letter == 'J') {
        letter = 'I';
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (table[i][j] == letter) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encrypt(string plaintext, string key) {
    char table[5][5];
    generate_table(key, table);
    string prepared_plaintext = prepare_input(plaintext);
    if (prepared_plaintext.length() % 2 == 1) {
        prepared_plaintext += 'X';
    }
    string ciphertext = "";
    for (int i = 0; i < prepared_plaintext.length(); i += 2) {
        char a = prepared_plaintext[i];
        char b = prepared_plaintext[i + 1];
        int row_a, col_a, row_b, col_b;
        find_position(table, a, row_a, col_a);
        find_position(table, b, row_b, col_b);
        if (row_a == row_b) {
            ciphertext += table[row_a][(col_a + 1) % 5];
            ciphertext += table[row_b][(col_b + 1) % 5];
        } else if (col_a == col_b) {
            ciphertext += table[(row_a + 1) % 5][col_a];
            ciphertext += table[(row_b + 1) % 5][col_b];
        } else {
            ciphertext += table[row_a][col_b];
            ciphertext += table[row_b][col_a];
        }
    }
    return ciphertext;
}
string decrypt(string ciphertext, string key) {
    string decrypted_text = "";
    char table[5][5];
    generate_table(key, table); // fixed parameter order
    for (int i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int row_a, col_a, row_b, col_b;
        find_position(table, a, row_a, col_a);
        find_position(table, b, row_b, col_b);
        if (row_a == row_b) {
            col_a = (col_a - 1 + 5) % 5;
            col_b = (col_b - 1 + 5) % 5;
        } else if (col_a == col_b) {
            row_a = (row_a - 1 + 5) % 5;
            row_b = (row_b - 1 + 5) % 5;
        } else {
            int temp = col_a;
            col_a = col_b;
            col_b = temp;
        }
        decrypted_text += table[row_a][col_a];
        decrypted_text += table[row_b][col_b];
    }
    return decrypted_text;
}



int main() {
string plaintext = "brownfox";
string key = "monarchy";
string ciphertext = encrypt(plaintext, key);
cout << "Ciphertext: " << ciphertext << endl;
string decrypted_plaintext = decrypt(ciphertext, key);
cout << "Decrypted plaintext: " << decrypted_plaintext << endl;
return 0;
}