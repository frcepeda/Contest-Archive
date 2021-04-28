#include <algorithm>
#include <iostream>

using namespace std;

int T;
string S;

int main(){
    cin >> T;

    for (int t = 1; t <= T; t++){
        string ans;

        cin >> S;

        int open = 0;
        for (char c: S){
            c -= '0';

            for (; open > c; open--)
                ans += ')';

            for (; open < c; open++)
                ans += '(';
            
            ans += c + '0';
        }

        for (; open > 0; open--)
            ans += ')';

        cout << "Case #" << t << ": " << ans << endl;
    }
}