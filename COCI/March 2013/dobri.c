#include <stdio.h>
#include <stdbool.h>

#define MAXN 5050
#define MINNUM -100000
#define MAXNUM 200100

int A[MAXN];
bool possible[MAXNUM];
int N;
int answer;

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++){
		for (j = i-1; j >= 0; j--){
			int t = A[i] - A[j] - MINNUM;
			if (t < MAXNUM && possible[t]){
				answer++;
				break;
			}
		}

		for (j = i; j >= 0; j--){
			int t = A[i] + A[j] - MINNUM;
			if (t < MAXNUM)
				possible[t] = true;
		}
	}

	printf("%d\n", answer);

	return 0;
}
