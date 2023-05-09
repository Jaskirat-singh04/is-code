#include <iostream>
#include <bitset>
#include <fstream>
using namespace std;

int main() {
    // Input a 4-bit message`
    bitset<4> message;
    cout << "Enter a 4-bit message (e.g. 1011): ";
    cin >> message;

    // Calculate the parity bits
    bitset<3> parity;
    parity[0] = message[0] ^ message[1] ^ message[3];
    parity[1] = message[0] ^ message[2] ^ message[3];
    parity[2] = message[1] ^ message[2] ^ message[3];

    // Create the encoded message
    bitset<7> encoded;
    encoded[6] = parity[0];
    encoded[5] = parity[1];
    encoded[4] = message[0];
    encoded[3] = parity[2];
    encoded[2] = message[1];
    encoded[1] = message[2];
    encoded[0] = message[3];

    // Output the encoded message
    cout << "Encoded message: " << encoded << endl;
     bitset<7> transmitted;
      transmitted=encoded;
      transmitted.flip(3);
     cout << " transmitted message: " <<transmitted<< endl;
    //  cin>>transmitted;
    //  ifstream MyReadFile("file.txt");
    //  while(getline(MyReadFile,transmitted)){
     


    // Compare the transmitted message with the encoded message to check for errors
    int error_bit = -1;
    for (int i = 0; i < 7; i++) {
        if (transmitted[i] != encoded[i]) {
            error_bit = i + 1;
            break;
        }
    }

    if (error_bit != -1) {
        cout << "Error detected at bit " << error_bit << endl;
        transmitted.flip(error_bit-1);
        cout << "Corrected message: " << transmitted << endl;
    } else {
        cout << "No errors detected." << endl;
    }
     
    return 0;
}