#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

constexpr int maxn = 1000100;
int N, K, L, s[maxn];

int main() {
    string in, risk;
    cin >> N >> K >> L;
    cin >> in >> risk;

    s[0] = 1;
    long long ans = 0, sum = 0;
    for (char c: in) {
        sum += risk.find(c) != string::npos;
        if (sum - K >= 0)
            ans += s[sum - K];
        s[sum]++;
    }
    cout << ans << endl;
}