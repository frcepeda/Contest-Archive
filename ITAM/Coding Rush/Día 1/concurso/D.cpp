#include <stdio.h>
#include <ctype.h>

char count[10];
char *num[10] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};

int main(){
	char c;

	while ((c = getchar()) != EOF)
		if (isdigit(c))
			count[c-'0']++;

	int i;

	for (i = 0; i < 10; i++)
		printf("Necesitas %d velita(s) %s\n", count[i], num[i]);

	return 0;
}

