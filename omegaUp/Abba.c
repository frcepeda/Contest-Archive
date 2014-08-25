#include <stdio.h>
#include <string.h>

#define MAXN 1000010
#define MAXA ('z' - 'a' + 1)

int p[MAXA], N, ans;
char str[MAXN];

int id(int x){
	if (p[x] == x)
		return x;
	return p[x] = id(p[x]);
}

int join(int a, int b){
	ans++;
	p[id(a)] = id(b);
}

int main(void){
	int i;

	scanf("%s", str);
	N = strlen(str);

	for (i = 0; i < MAXA; i++)
		p[i] = i;

	for (i = 0; i < N/2; i++)
		if (id(str[i] - 'a') != id(str[N-i-1] - 'a'))
			join(str[i] - 'a', str[N-i-1] - 'a');

	printf("%d\n", ans);

	return 0;
}
