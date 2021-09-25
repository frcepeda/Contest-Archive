#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int T;

const int INF = 1<<27;
const int P = 'Z' - 'A' + 1;
int d[256][256];

int cost(const string &s, char c) {
    int ret = 0;

    for (char x: s) {
        if (d[x][c] == INF) return INF;
        ret += d[x][c];
    }

    return ret;
}

bool isvowel(char x) {
    static string v("AEIOU");
    return v.find(x) != string::npos;
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++){
        for (int i = 'A'; i <= 'Z'; i++){
            for (int j = 'A'; j <= 'Z'; j++){
                d[i][j] = i == j ? 0 : isvowel(i) != isvowel(j) ? 1 : INF;
            }
        }

        string S;

        cin >> S;

        for (int k = 'A'; k <= 'Z'; k++)
            for (int i = 'A'; i <= 'Z'; i++)
                for (int j = 'A'; j <= 'Z'; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        int ans = INF;
        for (int k = 'A'; k <= 'Z'; k++) {
            ans = min(ans, cost(S, k));
        }

        cout << "Case #" << t << ": " << (ans < INF ? ans : -1) << "\n";
    }
}
