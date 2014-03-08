// 80/80 points
#include <stdio.h>

#define MAXN 25
#define MAXL 110

int N;
int words[MAXN];

int count(int i, int acc){
	if (i == N)
		return acc + 1 == (1<<26);
	return count(i+1, acc) + count(i+1, acc | words[i]);
}

int main(void){
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++){
		char str[MAXL];
		scanf("%s", str);
		for (j = 0; str[j]; j++)
			words[i] |= (1<<(str[j]-'a'));
	}

	printf("%d\n", count(0,0));

	return 0;
}
