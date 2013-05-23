#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

char *str;
int *fail;
int N;

int main(void){
	int i, curr;
	char c;
	bool firstTime = true;

	while (scanf("%d\n", &N) != EOF){
		if (!firstTime)
			putchar('\n');
		else
			firstTime = false;

		str = malloc(N+5);
		fail = malloc(sizeof(int) * (N+5));

		scanf("%s\n", str);

		fail[0] = fail[1] = 0;

		for (i = 2; i <= N; i++){
			fail[i] = fail[i-1];

			while (fail[i] && str[fail[i]] != str[i-1])
				fail[i] = fail[fail[i]];

			if (str[fail[i]] == str[i-1])
				fail[i]++;
		}

		curr = 0;

		for (i = 1, c = getchar(); isalpha(c); i++, c = getchar()){
			while (curr && str[curr] != c)
				curr = fail[curr];
			if (str[curr] == c)
				curr++;
			if (curr == N)
				printf("%d\n", i - N);
		}

		free(str);
		free(fail);
	}

	return 0;
}
