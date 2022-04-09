#include <iostream>
#include <array>

using namespace std;

int main(){
    int T;
    constexpr int target = 1000000;

    cin >> T;

    for (int t = 1; t <= T; t++){
        array<int,4> c;
        c.fill(target);

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 4; j++){
                int x;
                cin >> x;
                c[j] = min(c[j], x);
            }
        }

        int rem = target;
        for (int j = 0; j < 4; j++){
            c[j] = min(c[j], rem);
            rem -= c[j];
        }

        cout << "Case #" << t << ":";
        if (rem) {
            cout << " IMPOSSIBLE";
        } else {
            for (int j = 0; j < 4; j++){
                cout << " " << c[j];
            }
        }
        cout << "\n";
    }
}
