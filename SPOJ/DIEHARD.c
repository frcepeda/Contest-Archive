#include <stdio.h>

#define MAXHA 2510

int max(int a, int b){
	return a > b ? a : b;
}

int answer[MAXHA][MAXHA][3];

int f(int H, int A, int P){
	if (P == 0){
		H += 3;
		A += 2;
	} else if (P == 1) {
		H -= 5;
		A -= 10;
	} else {
		H -= 20;
		A += 5;
	}

	if (H <= 0 || A <= 0)
		return 0;
	if (answer[H][A][P])
		return answer[H][A][P];

	if (P == 0)
		return answer[H][A][P] = max(f(H,A,1), f(H,A,2)) + 1;
	if (P == 1)
		return answer[H][A][P] = max(f(H,A,0), f(H,A,2)) + 1;
	if (P == 2)
		return answer[H][A][P] = max(f(H,A,0), f(H,A,1)) + 1;
}

int main(void){
	int t, H, A;

	scanf("%d", &t);

	while (t--){
		scanf("%d %d", &H, &A);
		printf("%d\n", max(f(H,A,0), max(f(H,A,1), f(H,A,2))));
	}

	return 0;
}
