#include <iostream>
#include <string>
#include <cctype>

using namespace std;


bool isDigit(char c)
{
    string digits = "0123456789";
    return digits.find(c) != string::npos;
}

string transformString(const string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            result += s[i];

            int j = i + 1;
            string tmp = "";
            while (isDigit(s[j])) {
                tmp += s[j];
                j++;
            }

            i = j;
            if (tmp.length() > 2) {
                tmp = tmp.substr(0, 2);
            }
            result += tmp;
        }

        if (s[i] == ' ') {
            break;
        }
        else if (s[i] != '.') {
            result += s[i];
        }
        else {
            i--;
        }
    }

    return result;
}

int main()
{
    string s;
    cout << "Enter string: ";
    getline(cin, s);
    cout << transformString(s);

    return 0;
}