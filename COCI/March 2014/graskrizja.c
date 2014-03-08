// 32/160 points
#include <stdio.h>

int N;
int tr, lc, br, rc;

int main(void){
	int a, b;

	scanf("%d", &N);

	scanf("%d %d", &a, &b);
	tr = br = a;
	lc = rc = b;

	N--;
	while (N--){
		scanf("%d %d", &a, &b);
		if (tr < a) tr = a;
		if (br > a) br = a;
		if (lc > b) lc = b;
		if (rc < b) rc = b;
	}

	for (a = br; a <= tr; a++)
		for (b = lc; b <= rc; b++)
			printf("%d %d\n", a, b);

	return 0;
}
