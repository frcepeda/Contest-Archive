#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 30100

int a[MAXN], b[MAXN];
int aLen, bLen;
int d1, d2;

int cutoff, dcutoff;
int seq[MAXN];
int N;

void try(int i){
	for (; i < N; i++){
		bool aMatches = a[aLen-1] + d1 == seq[i];
		bool bMatches = !d2 || b[bLen-1] + d2 == seq[i];

		if (aMatches && bMatches && i >= cutoff){
			if (d1 == dcutoff){
				for (; i < N; i++)
					a[aLen++] = seq[i];
				break;
			} else if (!bLen || d2 == dcutoff || (!d2 && seq[i] - b[0] == dcutoff)){
				for (; i < N; i++)
					b[bLen++] = seq[i];
				break;
			}
		}
		
		if (aMatches){
			a[aLen++] = seq[i];
		} else if (bMatches){
			b[bLen++] = seq[i];
			if (bLen >= 2 && !d2)
				d2 = b[1] - b[0];
		} else return;
	}

	if (bLen == 0)
		b[bLen++] = a[--aLen];

	for (i = 0; i < aLen; i++)
		printf("%d%c", a[i], i != aLen-1 ? ' ' : '\n');

	for (i = 0; i < bLen; i++)
		printf("%d%c", b[i], i != bLen-1 ? ' ' : '\n');

	exit(0);
}

int main(void){
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &seq[i]);

	dcutoff = seq[N-1] - seq[N-2];
	for (cutoff = N-2; cutoff >= 0 && seq[cutoff+1] - seq[cutoff] == dcutoff; cutoff--);
	cutoff++;

	a[0] = seq[0];
	a[1] = seq[1];
	aLen = 2;
	d1 = a[1] - a[0];
	d2 = 0;

	try(2);

	b[0] = seq[1];
	a[1] = seq[2];
	aLen = 2;
	bLen = 1;
	d1 = a[1] - a[0];
	d2 = 0;

	try(3);

	a[0] = seq[1];
	a[1] = seq[2];
	b[0] = seq[0];
	aLen = 2;
	bLen = 1;
	d1 = a[1] - a[0];
	d2 = 0;

	try(3);

	printf("No solution\n");

	return 0;
}
