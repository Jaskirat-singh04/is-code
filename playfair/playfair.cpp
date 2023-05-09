#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class playfair
{
public:
    string msg;
    char n[5][5];
    void play(string k, string t, bool e)
    {
        createEncoder(k);
        getText(t, e);
        if (e)
            play(1);
        else
            play(-1);
        print();
    }

private:
    void play(int dir)
    {
        int j, k, p, q;
        string nmsg;
        for (string::const_iterator it = msg.begin(); it != msg.end(); it++)
        {
            if (getPos(*it++, j, k))
                if (getPos(*it, p, q))
                {
                    // for same row
                    if (j == p)
                    {
                        nmsg += getChar(j, k + dir);
                        nmsg += getChar(p, q + dir);
                    }
                    // for same column
                    else if (k == q)
                    {
                        nmsg += getChar(j + dir, k);
                        nmsg += getChar(p + dir, q);
                    }
                    else
                    {
                        nmsg += getChar(j, q);
                        nmsg += getChar(p, k);
                    }
                }
        }
        msg = nmsg;
    }
    void print() // print the solution
    {
        cout
            << "\n\n Solution:" << endl;
        string::iterator it = msg.begin();
        while (it != msg.end())
        {
            cout << *it;
            it++;
            cout << *it << " ";
            it++;
        }
        cout << endl
             << endl;
    }
    char getChar(int a, int b)
    { // get the characters
        return n[(a + 5) % 5][(b + 5) % 5];
    }
    bool getPos(char l, int &c, int &d)
    { // get the position
        for (int y = 0; y < 5; y++)
            for (int x = 0; x < 5; x++)
                if (n[y][x] == l)
                {
                    c = y;
                    d = x;
                    return true;
                }
        return false;
    }
    void getText(string t, bool e)
    { // get the original message
        for (string::iterator it = t.begin(); it != t.end(); it++)
        {
            // to choose J = I or no Q in the alphabet.
            *it = toupper(*it);
            if (*it < 65 || *it > 90)
                continue;
            if (*it == 'J')
                *it = 'I';
            msg += *it;
        }
        if (e)
        {
            string nmsg = "";
            size_t len = msg.length();
            for (size_t x = 0; x < len; x += 2)
            {
                nmsg += msg[x];
                if (x + 1 < len)
                {
                    if (msg[x] == msg[x + 1])
                        nmsg += 'X';
                    nmsg += msg[x + 1];
                }
            }
            msg = nmsg;
        }
        if (msg.length() & 1)
            msg += 'X';
    }
    void createEncoder(string key)
    { // creation of the key table
        if (key.length() < 1)
            key = "KEYWORD";
        key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string s = "";
        for (string::iterator it = key.begin(); it != key.end(); it++)
        {
            *it = toupper(*it);
            if (*it < 65 || *it > 90)
                continue;
            if (*it == 'J')
                continue;
            if (s.find(*it) == -1)
                s += *it;
        }
        copy(s.begin(), s.end(), &n[0][0]);
    }
};
int main(int argc, char *argv[])
{
    string k, i, msg;
    bool m, c;
    cout << "Encrpty or Decypt? ";
    cin >> i;
    c = (i[0] == 'e' || i[0] == 'E');
    cout << "Enter a key: ";
    cin >> k;
    cout << "Enter the message: ";
    cin >> msg;

    playfair pf;
    pf.play(k, msg, c);
    return 0;
}