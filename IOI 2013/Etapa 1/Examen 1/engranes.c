#include <stdio.h>
#include <stdbool.h>

#define MAXN 2000001

unsigned long long int N, M, T;
bool visited[MAXN], isStable[MAXN];
int colors[MAXN];

#define tooth(v) ((v) % N)

bool check(long long unsigned int valley){
	int start = tooth(valley);
	int color = colors[start];
	unsigned long long int curr;

	for (curr = tooth(start + M); curr != start; curr = tooth(curr + M)){
		visited[curr] = true;
		if (colors[curr] != color)
			return false;
	}

	return true;
}

int main(void){
	int i;

	scanf("%llu %llu %*d", &N, &M);

	for (i = 0; i < N; i++)
		scanf("%d", &colors[i]);

	scanf("%llu", &T);

	for (i = 0; i < N; i++){
		if (!visited[i]){
			visited[i] = true;
			if (check(i)){
				int curr;
				isStable[i] = true;
				for (curr = tooth(i + M); curr != i; curr = tooth(curr + M)){
					isStable[curr] = true;
				}
			}
		}
	}

	while (T--){
		unsigned long long int L;
		scanf("%llu", &L);
		printf("%d", isStable[L%N]);
	}
	putchar('\n');

	return 0;
}

