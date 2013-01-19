#include <stdio.h>
#include <stdlib.h>

#define MAXINTVL 100100

typedef struct {
	int first, second;
} pair;

typedef struct {
	int prev, next, coord;
} _linkedList;

int intCmp(int a, int b){
	return a > b ? 1 : a < b ? -1 : 0;
}

int pairCmp(const void *ap, const void *bp){
	int ret = intCmp(((pair *)ap)->first, ((pair *)bp)->first);
	if (ret)
		return ret;
	return intCmp(((pair *)ap)->second, ((pair *)bp)->second);
}

pair pairs[MAXINTVL];
pair pass[MAXINTVL*2];
int where[MAXINTVL];
int nextPlace = 2;

int N, K;

int main(void){
	int curr = 0, i, openCount = 0, answer = 0;

	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	
	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++){
		int num;
		char dir[10];
		scanf("%d %s", &num, dir);

		if (dir[0] == 'R'){
			pairs[i].first = curr;
			curr += num;
			pairs[i].second = curr;
		} else {
			pairs[i].second = curr;
			curr -= num;
			pairs[i].first = curr;
		}
	}

	qsort(pairs, N, sizeof(pair), pairCmp);

	for (i = 0; i < N; i++){
		pass[i].first = pairs[i].first;
		pass[i].second = -1;
		pass[i+N].first = pairs[i].second;
		pass[i+N].second = i;
	}

	N *= 2;
	qsort(pass, N, sizeof(pair), pairCmp);

	int lastCoord = pass[i].first;

	for (i = 0; i < N; i++){
		if (pass[i].second == -1){
			openCount++;

			if (openCount > K && lastCoord != pass[i].first)
				answer += pass[i].first - lastCoord;

		} else {
			if (openCount >= K && lastCoord != pass[i].first)
				answer += pass[i].first - lastCoord;

			openCount--;
		}

		lastCoord = pass[i].first;
	}

	printf("%d\n", answer);

	return 0;
}
