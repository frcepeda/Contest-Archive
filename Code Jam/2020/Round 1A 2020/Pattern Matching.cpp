#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 55;
int T, N;
string str[maxn];

string go(){
    string ans;
    int idx[maxn] = {0};

    for (int i = 0; i < N; i++){
        int s = str[i].find('*');
        int len = min(s, (int)ans.size());

        if (str[i].substr(0, len) != ans.substr(0, len))
            return "*";

        if (ans.size() < s)
            ans = str[i].substr(0, s);

        idx[i] = s+1;
    }

    for (int i = 0; i < N; i++){
        while (true){
            int ss = str[i].find('*', idx[i]);
            if (ss == string::npos) break;
            ans += str[i].substr(idx[i], ss - idx[i]);
            idx[i] = ss+1;
        }
    }

    string tail;

    for (int i = 0; i < N; i++){
        auto len = min(str[i].size() - idx[i], tail.size());

        reverse(str[i].begin() + idx[i], str[i].end());

        if (str[i].substr(idx[i], len) != tail.substr(0, len))
            return "*";

        if (tail.size() < str[i].size() - idx[i])
            tail = str[i].substr(idx[i]);
    }

    reverse(tail.begin(), tail.end());

    return ans + tail;
}

int main(){
    cin >> T;

    for (int t = 1; t <= T; t++){
        string ans;

        cin >> N;

        for (int i = 0; i < N; i++)
            cin >> str[i];

        cout << "Case #" << t << ": " << go() << endl;
    }
}