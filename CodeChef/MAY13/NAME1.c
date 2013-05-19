#include <stdio.h>
#include <stdbool.h>

#define MAXSTR 200010

int count[2][26];

int T, N;
char str[MAXSTR];

void readAndCount(int *c){
	int i;
	scanf("%s", str);
	for (i = 0; str[i] != '\0'; i++)
		c[str[i] - 'a']++;
}

bool check(void){
	int i;
	for (i = 0; i < 26; i++)
		if (count[0][i] < count[1][i])
			return false;
	return true;
}

int main(void){
	scanf("%d", &T);

	while (T--){
		int i;

		for (i = 0; i < 26; i++)
			count[0][i] = count[1][i] = 0;

		readAndCount(count[0]);
		readAndCount(count[0]);

		scanf("%d", &N);

		while (N--)
			readAndCount(count[1]);

		printf("%s\n", check() ? "YES" : "NO");
	}

	return 0;
}
