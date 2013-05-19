#include <stdio.h>
#include <stdbool.h>

#define MAXSTR 25010

int T;
char M[MAXSTR], W[MAXSTR];

bool isSubstr(char *a, char *b){
	for (; *a != '\0' && *b != '\0'; a++)
		if (*a == *b)
			b++;
	return *b == '\0';
}

int main(void){
	scanf("%d", &T);

	while (T--){
		scanf("%s%s", M, W);
		printf("%s\n", isSubstr(M,W) || isSubstr(W,M) ? "YES" : "NO");
	}

	return 0;
}
