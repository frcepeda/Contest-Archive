#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T, t, X, Y;
string s;
const int maxn = 1010;
int dp[maxn][2], v[maxn][2];

int c(int a, int b) {
    if (a == b) return 0;
    if (a == 0) return X;
    return Y;
}

int f(int i, int l) {
    if (i == s.size()) return 0;

    if (v[i][l] == t)
        return dp[i][l];

    v[i][l] = t;
    
    if (s[i] == '?') {
        dp[i][l] = min(f(i+1, 0) + c(l,0),
                       f(i+1, 1) + c(l,1));
    } else {
        dp[i][l] = f(i+1, s[i] == 'J') + c(l, s[i] == 'J');
    }

    return dp[i][l];
}

int main() {
    cin >> T;

    for (t = 1; t <= T; t++){
        cin >> X >> Y >> s;

        int ans = 0;

        if (s[0] == '?') {
            ans = min(f(1, 0), f(1, 1));
        } else {
            ans = f(1, s[0] == 'J');
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
