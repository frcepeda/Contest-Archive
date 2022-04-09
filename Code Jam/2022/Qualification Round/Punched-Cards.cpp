#include <iostream>

using namespace std;

int T, R, C;

int main() {
    cin >> T;

    string even[2], odd[2];

    for (int i = 0; i < 11; i++){
        even[0] += "+-";
        odd[0] += "|.";
    }

    even[1] = even[0];
    odd[1] = odd[0];

    even[1][0] = even[1][1] = odd[1][0] = odd[1][1] = '.';

    for (int t = 1; t <= T; t++){
        cout << "Case #" << t << ":\n";
        cin >> R >> C;

        int len = C*2 + 1;

        for (int i = 0; i < R; i++){
            cout << even[i == 0].substr(0, len) << '\n';
            cout << odd[i == 0].substr(0, len) << '\n';
        }

        cout << even[0].substr(0, len) << '\n';
    }
}
