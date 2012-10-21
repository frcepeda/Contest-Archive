#include <stdio.h>

#define MAXNUM 1000

int values[MAXNUM];
int vis[MAXNUM][MAXNUM];
int memo[MAXNUM][MAXNUM];

int max(int a, int b);
int max(int a, int b){
    return a > b ? a : b;
}

int negamax(int a, int b);
int negamax(int a, int b){
    if (a == b) {
        return values[a];
    }
    if (vis[a][b]) {
        return memo[a][b];
    }
    vis[a][b] = 1;
    return memo[a][b] = max(values[a] - negamax(a + 1, b), values[b] - negamax(a, b - 1));
}

int main (int argc, const char * argv[])
{
    int i, last, total = 0;
    scanf("%d", &last);
    for (i = 0; i < last; i++) {
        scanf("%d", &values[i]);
        total += values[i];
    }
    printf("%d\n", (total + negamax(0, last-1)) / 2);
    return 0;
}

