#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXR 1000010

int R[MAXR], digs[10];
int N;

int cnt(int x){
	if (x == 0) return 1;
	int r = 0;
	for (; x; x /= 10, r++);
	return r;
}

bool check(const int s, int Q){
	int i, j = s;

	for (i = 0; i < s && j < N; i++){
		int k = 0, l = R[i]*Q;

		if (l != 0){
			for (; k < l && j < N; j++)
				k = k*10 + R[j];

			if (k != l) return false;
		} else {
			if (R[j++] != 0) return 0;
		}
	}

	return i == s && j == N;
}

int main(void){
	int i, j, k;

	while (isdigit(R[N++] = getchar()));
	N--;
	
	for (i = 0; i < N; i++)
		R[i] -= '0';

	for (i = 1; i < N; i++){
		digs[R[i-1]]++;

		int acc = 0;
		for (j = 0; j <= 7 && i+j < N; j++){
			acc = acc*10 + R[i+j];

			if (acc % R[0] == 0){
				int len = 0, Q = acc / R[0];

				if (Q > 1000000) break;

				for (k = 0; k <= 9; k++)
					len += digs[k] * cnt(Q*k);

				if (len == N-i && check(i,Q)){
					for (j = 0; j < i; j++)
						printf("%d", R[j]);
					printf("\n%d\n", Q);
					return 0;
				}
			}
		}
	}

	return 1;
}
