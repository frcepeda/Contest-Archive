#include <iostream>
#include <cctype>
#include <string>

using namespace std;
int N;

int main() {
    string str;
    bool b, i;

    cin >> N;
    getline(cin, str);

    while (N--) {
        b = true;
        i = true;
        getline(cin, str);
        for (int j = 0; j < str.length(); ++j) {
            char c = str[j];
            if (c == '*') {
                if (b) {
                    str.replace(j, 1, "<b>");
                    b = false;
                } else {
                    str.replace(j, 1, "</b>");
                    b = true;
                }
            }

            if (c == '_') {
                if (i) {
                    str.replace(j, 1, "<i>");
                    i = false;
                } else {
                    str.replace(j, 1, "</i>");
                    i = true;
                }
            }
        }
        cout << str << endl;
    }
}
