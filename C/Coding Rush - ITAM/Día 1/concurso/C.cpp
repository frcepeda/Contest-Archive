#include <stdio.h>
#include <ctype.h>

char l[] = "0abcdefghijklmnñopqrstuvwxyz";

int main(){
	int n;

	while (scanf("%d", &n) != EOF)
		printf("%c", l[n]);

	printf("\n");

	return 0;
}

