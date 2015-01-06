#include <cstdio>

using namespace std;

#define MAXK 51

char a[100], b[100];
int k;
unsigned long long choose[MAXK][MAXK];

int main() {
	int t, T, i, j;
	
	for (i = 0; i < MAXK; i++){
		choose[i][0] = choose[i][i] = 1;
		for (j = 1; j < i; j++)
			choose[i][j] = choose[i-1][j-1] + choose[i-1][j];
	}
	
	scanf("%d", &T);
	
	for (t = 1; t <= T; t++){
		scanf(" (%[a-z]+%[a-z])^%d ", a, b, &k);
		
		printf("Case %d: ", t);
		for (i = k; i >= 0; i--){
			if (choose[k][i] != 1)
				printf("%llu*", choose[k][i]);
			if (i)
				printf("%s", a);
			if (i > 1)
				printf("^%d", i);
			if (i && (k-i))
				printf("*");
			if (k-i)
				printf("%s", b);
			if (k-i > 1)
				printf("^%d", k-i);
			putchar(i ? '+' : '\n');
		}
	}
}