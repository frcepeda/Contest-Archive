#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solve(const string &str) {
    string ans;

    for (int i = 0, j; i < str.size(); i = j) {
        for (j = i; j < str.size() && str[i] == str[j]; j++);

        string sub = str.substr(i, j-i);
        ans += sub;

        if (j != str.size() && str[i] < str[j]) {
            ans += sub;
        }
    }

    return ans;
}

int main() {
    int T;

    cin >> T;

    for (int t = 1; t <= T; t++){
        string str;
        cin >> str;
        cout << "Case #" << t << ": " << solve(str) << "\n";
    }
}
