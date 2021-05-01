#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1<<20;
int T;

string flip(string x) {
    for (auto &c: x) {
        c = '0' + 1 - (c - '0');
    }

    reverse(x.begin(), x.end());

    while (!x.empty() && x.back() == '0') {
        x.pop_back();
    }

    reverse(x.begin(), x.end());

    if (x.empty()) {
        x = "0";
    }

    return x;
}

int works(string S, string E, int k) {
    int adj = 0;

    if (S == "0") {
        S = "1";
        adj++;
    }

    if (S == E) {
        return adj;
    }

    for (int i = 0; i < k; i++){
        if (S == "0") return INF;
        S = flip(S);
    }

    if (S == "0") {
        if (E == "0") return adj + k;
        S = "";
    }

    if (E.compare(0, S.size(), S) != 0) {
        return INF;
    }

    E = E.substr(S.size());
    int c = 0;
    for (int i = 1; i < E.size(); i++){
        if (E[i] != E[i-1]) {
            c++;
        }
    }

    if (c < k || (c == k && (E[0] - '0') == k % 2)) {
        return adj + k + E.size();
    } else {
        return INF;
    }
}

int main(){
    cin >> T;

    for (int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";

        string S, E;
        cin >> S >> E;

        int ans = S != E ? INF : 0;

        for (int i = 0; i <= S.size(); i++){
            ans = min(ans, works(S, E, i));
        }

        if (ans == INF) cout << "IMPOSSIBLE\n";
        else cout << ans << "\n";
    }
}
