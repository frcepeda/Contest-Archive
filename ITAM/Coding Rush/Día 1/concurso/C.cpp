#include <stdio.h>
#include <ctype.h>

char l[] = "0abcdefghijklmn�opqrstuvwxyz";

int main(){
	int n;

	while (scanf("%d", &n) != EOF)
		printf("%c", l[n]);

	printf("\n");

	return 0;
}

