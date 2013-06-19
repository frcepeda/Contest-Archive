#include <stdio.h>

#define MAXN 10010

int T, i;
char str[MAXN];

int max(int a, int b){
	return a > b ? a : b;
}

int depth(void){
	if (str[i++] == 'l')
		return 1;
	else
		return max(depth(), depth()) + 1;
}

int main(void){
	scanf("%d", &T);

	while (T--){
		scanf("%s", str);
		i = 0;
		printf("%d\n", depth() - 1);
	}

	return 0;
}
