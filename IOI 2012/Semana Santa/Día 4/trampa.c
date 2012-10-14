#include <stdio.h>
#include <stdlib.h>

#define MAXLASERS 100000+5

typedef struct {
	unsigned int start, end;
} laser;

int intCmp(int a, int b){
	if (a > b) return 1;
	if (b > a) return -1;
	return 0;
}

int laserCmp(const void *a, const void *b){
	int s = intCmp(((laser *)a)->start, ((laser *)b)->start);
	if (!s)
		s = intCmp(((laser *)a)->end, ((laser *)b)->end);
	return s;
}

laser lasers[MAXLASERS];
int laserCount;

unsigned int sequence[MAXLASERS];
int length[MAXLASERS];
int size;

int binary_search(int hi, int key){
	int lo = 1;
	int max = 0;
	while (lo <= hi){
		int mid = (lo + hi) / 2;
		if (length[mid] <= key){
			if (mid > max) max = mid;
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}
	return max;
}

int main(void){
	int i;

	scanf("%u", &laserCount);

	for (i = 0; i < laserCount; i++)
		scanf("%u %u", &lasers[i].start, &lasers[i].end);

	qsort(lasers, laserCount, sizeof(laser), laserCmp);

	for (i = 0; i < laserCount; i++)
		sequence[i] = lasers[i].end;

	for (i = 0; i < laserCount; i++){
		int j = binary_search(size, sequence[i]);
		if (j == size || length[j+1] >= sequence[i]){
			length[j+1] = sequence[i];
			if (j+1 > size) size = j+1;
		}
	}

	printf("%d\n", size);

	return 0;
}

