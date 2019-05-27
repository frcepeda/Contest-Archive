#include <iostream>

using namespace std;

int T;

int main(){
    cin >> T;

    string s;
    for (int t = 1; t <= T; t++){
        int n;

        cin >> n >> s;

        for (char &c: s)
            c = c == 'E' ? 'S' : 'E';
        
        cout << "Case #" << t << ": " << s << endl;
    }
}
