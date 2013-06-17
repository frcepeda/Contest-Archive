#include <stdio.h>

#define MAXNUM 2001
#define OFF 1000

int N, T;
int count[MAXNUM];

int main(void){
	int i;

	scanf("%d", &T);

	while (T--){
		for (i = 0; i < MAXNUM; i++)
			count[i] = 0;

		scanf("%d", &N);

		for (i = 0; i < N; i++){
			int n;
			scanf("%d", &n);
			count[n + OFF]++;
		}

		for (i = 0; i < MAXNUM; i++)
			if (count[i] > N/2)
				break;

		if (i < MAXNUM)
			printf("YES %d\n", i - OFF);
		else
			printf("NO\n");
	}

	return 0;
}
