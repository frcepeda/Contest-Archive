#include <stdio.h>
#include <stdbool.h>

#define MAXN 1010

typedef struct {
	int start, end;
} intvl;

bool taken[MAXN];
intvl people[MAXN];
int N, L;

int main(void){
	int i, j, most = -1, mosti, count;

	scanf("%d", &L);
	scanf("%d", &N);

	for (i = 0; i < N; i++){
		scanf("%d %d", &people[i].start, &people[i].end);

		if (most < people[i].end - people[i].start){
			most = people[i].end - people[i].start;
			mosti = i;
		}
	}

	printf("%d\n", mosti + 1);

	most = 0;

	for (i = 0; i < N; i++){
		for (count = 0, j = people[i].start; j <= people[i].end; j++){
			if (!taken[j]){
				taken[j] = true;
				count++;
			}
		}

		if (count > most){
			most = count;
			mosti = i;
		}
	}

	printf("%d\n", mosti + 1);

	return 0;
}
