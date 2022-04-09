#include <iostream>
#include <set>

using namespace std;

int main(){
    int T, N;

    cin >> T;

    for (int t = 1; t <= T; t++){
        multiset<int> S;

        cin >> N;

        for (int i = 0; i < N; i++){
            int Si;
            cin >> Si;
            S.insert(Si);
        }

        int ans = 0;
        while (!S.empty()) {
            if (*S.begin() > ans){
                ans++;
            }
            S.erase(S.begin());
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
}
