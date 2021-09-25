#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int T;
string S;

int c(char x) {
    return x == 'F' ? 2 : x == 'X' ? 1 : 0;
}

int main(){
    cin >> T;

    const long long mod = 1000000007;

    for (int t = 1; t <= T; t++){
        int N;

        cin >> N >> S;

        long long ans = 0;
        long long sum = 0, start = 0, startsum = 0;
        int last = 2, fs = 0, first = 2, startfs = 0;
        bool allfs = true;

        for (int i = 0; i < S.size(); i++){
            if (S[i] == '.') {
                auto newstart = (start + start) % mod;
                auto newstartsum = (startsum + startsum) % mod;
                auto newsum = (sum + startsum * sum) % mod;

                if (first == 1 - last) {
                    newsum = (newsum + (i - startfs) * (i - fs)) % mod;
                    newstart = (newstart + 1) % mod;
                    newstartsum = (newstartsum + i) % mod;
                }

                ans = (ans + newsum) % mod;
                sum = (sum + newsum) % mod;
                start = newstart;
                startsum = newstartsum;

                if (allfs) {
                    fs = (fs * 2) % mod;
                    startfs = (fs * 2) % mod;
                }
            } else {
                if (first == 2) {
                    if (S[i] == 'F') {
                        startfs++;
                    } else {
                        first = c(S[i]);
                    }
                }

                if (c(S[i]) == 1 - last) {
                    start = (start + 1) % mod;
                    sum = (sum + i - fs) % mod;
                }

                ans = (ans + sum) % mod;
                startsum = (startsum + start) % mod;

                if (S[i] != 'F') {
                    last = c(S[i]);
                    fs = 0;
                    allfs = false;
                } else {
                    fs++;
                }
            }
            //cerr << i << ": " << sum << " " << start << endl;
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
}
