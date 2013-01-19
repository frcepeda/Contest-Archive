#include <stdio.h>

#define MAXSTR 100010

char str[MAXSTR];
int N, count;

int Astack[MAXSTR];
int Bstack[MAXSTR];

int main(void){
	int A, B, i;

	scanf("%d", &N);

	while (N--){
		scanf("%s", str);

		A = B = 0;
		for (i = 0; str[i]; i++){
			if (str[i] == 'A'){
				if (A && (!B || Astack[A-1] > Bstack[B-1]))
					A--;
				else
					Astack[A++] = i;
			} else {
				if (B && (!A || Bstack[B-1] > Astack[A-1]))
					B--;
				else
					Bstack[B++] = i;
			}
		}

		if (A == 0 && B == 0)
			count++;
	}

	printf("%d\n", count);
	
	return 0;
}
