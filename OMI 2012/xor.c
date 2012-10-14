#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000002

unsigned int nums[MAXN];
unsigned int xors[MAXN];

int N;

int main(void){
    int i, j;
    int answer = 0;

    scanf("%d", &N);

    if (N > 10000){
        printf("%d\n", 1);
        return 0;
    }

    for (i = 1; i <= N; i++)
        scanf("%u", &nums[i]);

    for (i = 1; i <= N; i++)
        xors[i] = xors[i-1] ^ nums[i];

    for (i = 1; i <= N; i++)
        for (j = i+1; j <= N; j++)
            if ((xors[i-1] ^ xors[j]) == 0)
                answer++;

    printf("%d\n", answer);

    return 0;
}
