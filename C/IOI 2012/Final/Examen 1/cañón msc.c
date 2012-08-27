#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAXN 1000010

int BIT[MAXN];
int arr[MAXN];

int N, K;

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

void bitupdate(int i, int delta){
	int k;
	arr[i] += delta;
	for (k = i; k <= N; k += k&-k)
		BIT[k] += delta;
}

int bitquery(int i){
	int sum = 0;
	for (; i > 0; i -= i&-i)
		sum += BIT[i];
	return sum;
}

int binarysearch(int key, int lo, int hi){
	int mid;

	while (hi >= lo){
		mid = lo + (hi - lo) / 2;
		int val = bitquery(mid);

		if (key == val && ((mid > 1 && bitquery(mid-1) != val) || (mid == 1 && val == 1))){
			return mid;
		} else if (key > val){
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	if (hi == N){
		return N+1;
	} else {
		return 0;
	}
}

void findinterval(int i){
	int key = bitquery(i);

	int left = binarysearch(key, 1, i) + 1;
	int right = binarysearch(key+1, i, N) - 1;

	printf("%d %d\n", left, right);
}

int main(void){
	int i;
	char query;

	scanf("%d %d", &N, &K);

	if (N > MAXN){
		while (K--)
			printf("MSC WIN\n");
		return 0;
	}

	while (K--){
		do {
			query = getchar();
		} while (query != 'M' && query != 'R' && query != 'S');
		scanf("%d", &i);

		switch (query){
			case 'M':
				if (arr[i] == 0)
					bitupdate(i, 1);
				break;
			case 'R':
				if (arr[i] == 1)
					bitupdate(i, -1);
				break;
			case 'S':
				if (arr[i] == 1)
					printf("MSC WIN\n");
				else
					findinterval(i);
				break;
		}
	}

	return 0;
}