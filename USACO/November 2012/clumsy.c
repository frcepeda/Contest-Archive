#include <stdio.h>

#define MAXSTRING 100010

char string[MAXSTRING];

int main(void){
	freopen("clumsy.in", "r", stdin);
	freopen("clumsy.out", "w", stdout);

	fgets(string, MAXSTRING, stdin);

	int i, answer = 0, depth = 0;

	for (i = 0; string[i] != '\n' && string[i] != '\0'; i++){
		depth += string[i] == '(' ? 1 : -1;
		if (depth < 0){
			depth = 1;
			answer++;
		}
	}
	answer += depth / 2;

	printf("%d\n", answer);
	
	return 0;
}
