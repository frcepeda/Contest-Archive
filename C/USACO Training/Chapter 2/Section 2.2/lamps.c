/*
    ID: frceped1
    LANG: C
    TASK: lamps
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("lamps.in", "r", stdin); freopen("lamps.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXN 105
#define MAXSTATES (1<<4)

typedef enum {
	unknown,
	on,
	off
} input;

input final[MAXN];
char states[MAXSTATES][MAXN];
int finalStates[MAXSTATES];
int finalStatesCount;
bool isReachable[MAXSTATES];
int N, C;
bool isDup[MAXSTATES];

int stateCmp(const void *ap, const void *bp){
	int a = *(int *)ap;
	int b = *(int *)bp;
	int i;

	for (i = 1; i <= N; i++){
		if (states[a][i] != states[b][i]){
			if (states[a][i]){
				return 1;
			} else {
				return -1;
			}
		}
	}

	if (a < b)
		isDup[b] = true;
	else
		isDup[a] = true;

	return 0;
}

int bitCount(int i){
	int count = 0;
	while (i){
		count++;
		i -= i&-i;
	}
	return count;
}

void button1(char lamps[]){
	int i;
	for (i = 1; i <= N; i++)
		lamps[i] ^= true;
}

void button2(char lamps[]){
	int i;
	for (i = 1; i <= N; i += 2)
		lamps[i] ^= true;
}

void button3(char lamps[]){
	int i;
	for (i = 2; i <= N; i += 2)
		lamps[i] ^= true;
}

void button4(char lamps[]){
	int i;
	for (i = 1; i <= N; i += 3)
		lamps[i] ^= true;
}

void (* button[4])(char []) = {button1, button2, button3, button4};

bool isValid(int i){
	if (i != 0 && (i > C || (C - i) % 2 != 0))
		return false;
	return true;
}

int main(void){
	openFiles();

	int i, j;

	scanf("%d", &N);
	scanf("%d", &C);

	while (scanf("%d", &i), i != -1)
		final[i] = on;

	while (scanf("%d", &i), i != -1)
		final[i] = off;

	for (i = 0; i < MAXSTATES; i++){
		int count = bitCount(i);
		if (isValid(count)){
			isReachable[i] = true;
			int currButton = 0;
			button1(states[i]);
			for (j = 1; j < MAXSTATES; j <<= 1, currButton++){
				if (i & j){
					button[currButton](states[i]);
				}
			}
		}
	}

	for (i = 0; i < MAXSTATES; i++){
		if (isReachable[i]){
			for (j = 1; j <= N; j++){
				if ((final[j] == on && states[i][j] != true) || (final[j] == off && states[i][j] != false)){
					isReachable[i] = false;
					break;
				}
			}
		}
	}

	for (i = 0; i < MAXSTATES; i++)
		if (isReachable[i])
			finalStates[finalStatesCount++] = i;

	qsort(finalStates, finalStatesCount, sizeof(int), stateCmp);

	for (i = 0; i < finalStatesCount; i++){
		if (isDup[finalStates[i]])
			continue;

		for (j = 1; j <= N; j++){
			printf("%d", states[finalStates[i]][j]);
		}
		printf("\n");
	}

	if (!finalStatesCount)
		printf("IMPOSSIBLE\n");

	return 0;
}
