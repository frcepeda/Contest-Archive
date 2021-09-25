#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> dioPrimes = {
    2,
    3,
    5,
    7,
    37,
    73,
    313,
    347,
    353,
    373,
    383,
    743,
    797,
    3467,
    7643,
    34673,
    37643,
    76367,
    79397,
    7693967,
    799636997,
};

int T;

int main() {
    cin >> T;

    while (T--){
        int a, b, ans = 0;
        cin >> a >> b;

        for (auto x: dioPrimes){
            if (a <= x && x <= b){
                ans++;
            }
        }

        cout << ans << endl;
    }
}
