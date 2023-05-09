#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <bitset>
using namespace std;

long long e, d, n;
// Returns the greatest common divisor of two integers a and b
long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

// Generates RSA key pair
void generateRSAKeys(long long &e, long long &d, long long &n)
{
    long long p = 71;
    long long q = 73;
    long long phi_n;
    // Step 1: Select two large random prime numbers
    // Step 2: Calculate n = p*q
    n = p * q;
    // Step 3: Calculate phi(n) = (p-1)*(q-1)
    phi_n = (p - 1) * (q - 1);
    // Step 4: Select an integer e such that 1 < e < phi(n) and gcd(e, phi(n)) = 1
    e = 2;
    while (gcd(e, phi_n) != 1)
    {
        e++;
    }

    // Step 5: Calculate d such that d*e mod phi(n) = 1
    long long a1 = 1, a2 = 0, b1 = 0, b2 = 1, d1 = phi_n, d2 = e, temp;

    while (d2 != 1)
    {
        // k
        long long k = (d1 / d2);

        // a
        temp = a2;
        a2 = a1 - (a2 * k);
        a1 = temp;

        // b
        temp = b2;
        b2 = b1 - (b2 * k);
        b1 = temp;

        // c
        temp = d2;
        d2 = d1 - (d2 * k);
        d1 = temp;
    }
    d = b2;

    if (d > phi_n)
        d = d % phi_n;
    else if (d < 0)
        d = d + phi_n;

    // cout<<"Private Key is:"<<d<<endl;
}

// Function to compute the modular exponentiation of a number
int modular_exponentiation(int base, int exponent, int mod)
{
    int result = 1;
    base = base % mod;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent / 2;
        base = (base * base) % mod;
    }
    return result;
    // return (int(pow(base, exponent)) % mod);
}

// Function to compute the signature of a message using RSA
int rsa_sign(string message)
{
    int hash = 0;
    for (int i = 0; i < message.length(); i++)
    {
        hash += int(message[i]);
    }
    cout << "hash: " << hash << endl;
    int signature = modular_exponentiation(hash, d, n);

    return signature;
}

// Function to verify the authenticity of a signature using RSA
bool rsa_verify(string message, int signature)
{
    int hash = 0;
    for (int i = 0; i < message.length(); i++)
    {
        hash += int(message[i]);
    }
    cout << "Message M: " << hash << endl;

    int decrypted_signature = modular_exponentiation(signature, e, n);
    cout << "Message M1: " << decrypted_signature << endl;
    if (decrypted_signature == hash)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    generateRSAKeys(e, d, n);
    // Print the public key (e, n)
    cout << "Public Key: (" << e << ", " << n << ")" << endl;
    // Print the private key (d, n)
    cout << "Private Key: (" << d << ", " << n << ")" << endl;

    string message_str = "rahul";
    cout << "Original message: " << message_str << endl;

    // Example usage of RSA signature generation and authentication

    int signature = rsa_sign(message_str);
    cout << "Signature: " << signature << endl;

    bool is_authentic = rsa_verify(message_str, signature);
    if (is_authentic)
    {
        cout << "Signature is authentic." << endl;
    }
    else
    {
        cout << "Signature is not authentic." << endl;
    }

    return 0;
}
