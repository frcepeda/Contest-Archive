#include <string>
#include <optional>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int T, N;

struct board {
    string s;
    board() {}
    board(string s): s(s) {}
    char& get(int r, int c) {
        return s[r*N+c];
    }
    const char& get(int r, int c) const {
        return s[r*N+c];
    }
    bool operator <(const board &b) const { return s < b.s; }
};

optional<pair<int,board>> row(const board &b, int r) {
    board newboard = b;
    int cost = 0;
    for (int i = 0; i < N; i++){
        if (b.get(r, i) == 'O') return nullopt;
        cost += b.get(r, i) != 'X';
        newboard.get(r, i) = 'X';
    }
    return optional(make_pair(cost, newboard));
}

optional<pair<int,board>> col(const board &b, int c) {
    board newboard = b;
    int cost = 0;
    for (int i = 0; i < N; i++){
        if (b.get(i, c) == 'O') return nullopt;
        cost += b.get(i, c) != 'X';
        newboard.get(i, c) = 'X';
    }
    return optional(make_pair(cost, newboard));
}

int main() {
    cin >> T;

    for (int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        cin >> N;

        board b;
        b.s.resize(N*N+1);

        set<board> boards[N*N+1];

        for (int i = 0; i < N; i++){
            cin >> &b.get(i, 0);
        }

        for (int i = 0; i < N; i++){
            auto ri = row(b, i);
            auto ci = col(b, i);
            if (ri) {
                boards[ri->first].insert(ri->second);
            }
            if (ci) {
                boards[ci->first].insert(ci->second);
            }
        }

        bool impossible = true;

        for (int i = 0; i < N*N+1; i++){
            if (!boards[i].empty()){
                cout << i << " " << boards[i].size() << "\n";
                impossible = false;
                break;
            }
        }

        if (impossible) {
            cout << "Impossible\n";
        }
    }
}
