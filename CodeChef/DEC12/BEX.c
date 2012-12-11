#include <stdio.h>

#define MAXSTACK 200010
#define MAXLEN 30

char name[MAXSTACK][MAXLEN];
int remaining[MAXSTACK];
int willRemove[MAXSTACK];
int nextStack;
int N;

int main(void){
	int i;
	scanf("%d", &N);

	while (N--){
		scanf("%d", &i);

		if (i == -1){
			nextStack--;
			printf("%d %s\n", willRemove[nextStack], name[nextStack]);
		} else {
			scanf("%s", name[nextStack]);
			if (i == 0) continue;

			if (nextStack == 0 || i <= remaining[nextStack-1]){
				willRemove[nextStack] = 0;
				remaining[nextStack] = i;
				nextStack++;
			} else {
				willRemove[nextStack-1]++;
			}
		}
	}

	return 0;
}

