#include <stdio.h>

#define MAXN 100100

int answer;
int a[MAXN], n;

int main(void){
	int i, j;

	scanf("%d", &n);

	a[0] = -1;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (i = 0; i <= n; i++){
		int c;
		for (j = i; j <= n && (j == i || a[j] == a[j-1]); j++);
		c = j - i;
		if (c > 1){
			for (j--; c >= 2; j--, c -= 2)
				a[j]++;
			i = j;
			answer += c != 1;
		} else if (i != n) {
			answer += a[i+1] - a[i] - (c == 1);
		}
	}

	printf("%d\n", answer);

	return 0;
}
