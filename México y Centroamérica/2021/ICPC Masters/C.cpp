#include <cstdio>
#include <set>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

typedef array<short,8> cont;

struct state {
    cont x;
    int c;

    bool operator < (const state &other) const {
        return c > other.c || c == other.c && x > other.x;
    }
};

state start, goal;

int go() {
    priority_queue<state> q;
    set<cont> v;

    auto tryGo = [&](state &curr, int x, int y) {
        swap(curr.x[x], curr.x[y]);
        curr.c += curr.x[x] + curr.x[y];

        if (v.find(curr.x) == v.end()) {
            q.push(curr);
        }

        curr.c -= curr.x[x] + curr.x[y];
        swap(curr.x[x], curr.x[y]);
    };

    q.push(start);

    while (true) {
        state curr = q.top(); q.pop();

        if (curr.x == goal.x) return curr.c;

        if (!v.insert(curr.x).second) continue;

        for (int i = 0; i < 3; i++) {
            tryGo(curr, i, i+1);
            tryGo(curr, i+4, i+4+1);
        }

        for (int i = 0; i < 4; i++) {
            tryGo(curr, i, i+4);
        }
    }
}

int main() {
    start.c = 0;

    for (int i = 0; i < 8; i++){
        scanf("%hd", &start.x[i]);
    }

    for (int i = 0; i < 8; i++){
        scanf("%hd", &goal.x[i]);
    }

    printf("%d\n", go());
}
