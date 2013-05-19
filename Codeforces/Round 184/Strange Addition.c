#include <stdio.h>
#include <stdbool.h>

#define MAXDIG 3
#define MAXN 110

bool inUse[MAXDIG];
int d[MAXN], k;
int answer;
int toPrint[MAXN], p;

int digCount(int a){
	int r;
	while (a){
		r += !!(a % 10);
		a /= 10;
	}
	return r;
}

int intCmp(const void *ap, const void *bp){
	return digCount(*(int *)ap) - digCount(*(int *)bp);
}

int main(void){
	int i, j, t;
	
	scanf("%d", &k);

	for (i = 0; i < k; i++){
		scanf("%d", &d[i]);
		if (!d[i]){
			answer++;
			k--;
			toPrint[p++] = 0;
		}
	}

	qsort(d, k, sizeof(int), intCmp);

	for (i = 0; i < k; i++){
		bool willadd = true;

		for (j = 0, t = d[i]; t; j++, t /= 10)
			if (t % 10 && inUse[j])
				willadd = false;

		if (willadd){
			answer++;
			toPrint[p++] = d[i];
			for (j = 0, t = d[i]; t; j++, t /= 10)
				if (t % 10)
					inUse[j] = true;
		}
	}

	printf("%d\n", answer);

	for (i = 0; i < p; i++)
		printf("%s%d", i > 0 ? " " : "", toPrint[i]);
	printf("\n");

	return 0;
}
