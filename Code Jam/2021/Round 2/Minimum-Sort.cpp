#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

int T, N;

int query(int a, int b) {
    printf("M %d %d\n", a, b);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1) exit(0);
    return x;
}

void doswap(int a, int b) {
    printf("S %d %d\n", a, b);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1) exit(0);
}

void done() {
    printf("D\n");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    if (x == -1) exit(0);
}

int main(){
    scanf("%d %d", &T, &N);

    for (int t = 1; t <= T; t++){
        for (int i = 1; i < N; i++){
            auto x = query(i, N);
            if (i != x) doswap(i, x);
        }
        done();
    }
}
