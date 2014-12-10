#include <cstdio>

using namespace std;

char sol[16][40000];
int len[16];

int main(void){
    int i, j, N;

    for (i = 1; i < 16; i++){
        len[i] = 2 * len[i-1] + 1;
        for (j = 0; j < len[i-1]; j++) sol[i][j] = sol[i-1][j];
        sol[i][len[i-1]] = 'L';
        for (j = 0; j < len[i-1]; j++) sol[i][len[i]-1-j] = sol[i-1][j] == 'L' ? 'R' : 'L';
    }

    while (scanf("%d", &N), (N != -1))
        printf("%s\n", sol[N]);
}
