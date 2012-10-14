#include <stdio.h>

#define MAXNUM 100005

#define summationUpTo(n) (((n)*((n)+1))/2)

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

typedef struct {
	int height, sails;
} mast;

int mastCompare(mast *a, mast *b){
	return a->height - b->height ;
}

mast masts[MAXNUM];
int mastCount;

int differences[MAXNUM];
int maxIndex = 1;

int BIT[MAXNUM];

int update(int idx, int diff){
	differences[idx] += diff;

	int i;
	for (i = idx; i < MAXNUM; i += i&-i)
		BIT[i] += diff;
}

long long int getRange(int idx){
	long long int answer = 0;
	int i;

	for (i = idx; i > 0; i -= i&-i)
		answer += BIT[i];
	
	return answer;
}

long long int getInefficiency(void){
	long long int answer = 0;
	int i;

	long long int curr = 0;
	for (i = 1; i <= maxIndex; i++){
		curr += differences[i];
		answer += summationUpTo(curr-1);
	}

	return answer;
}

int getStart(int point){
	int hi = point, lo = 1, mid;

	while (lo < hi){
		mid = lo + ((hi - lo) / 2);

		if (getRange(point) - getRange(mid-1) == 0){
			hi = mid;
		} else {
			lo = mid + 1;
		}
	}
	
	return max(1, lo-1);
}

int getEnd(int point){
	int hi = maxIndex, lo = point, mid;

	while (lo < hi){
		mid = lo + ((hi - lo + 1) / 2);

		if (getRange(mid) - getRange(point) == 0){
			lo = mid;
		} else {
			hi = mid - 1;
		}
	}

	return lo;
}

void magic(int start, int end){
	if (differences[start]){
		update(start, 1);
		update(end+1, -1);
	} else {
		int rangeStart = getStart(start);
		int rangeEnd = getEnd(start);

		int sizeofChunk = rangeEnd - start + 1;

		update(rangeStart, 1);
		update(rangeStart + sizeofChunk, -1);

		if (rangeEnd+1 <= maxIndex){
			update(rangeEnd+1, 1);
			update(maxIndex+1, -1);
		}
	}
}

int main(void){
	int i;

	scanf("%d", &mastCount);

	for (i = 0; i < mastCount; i++)
		scanf("%d %d", &masts[i].height, &masts[i].sails);

	qsort(masts, mastCount, sizeof(mast), mastCompare);

	for (i = 0; i < mastCount; i++){
		maxIndex = masts[i].height;
		magic(maxIndex - masts[i].sails + 1, maxIndex);
	}

	printf("%lld\n", getInefficiency());

	return 0;
}

