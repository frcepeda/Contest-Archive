// Accepted
#include <stdio.h>
#include <ctype.h>

int main(void){
	char c;

	while ((c = getchar()) != EOF)
		if (c != '\n')
			putchar(c-7);
		else putchar(c);

	return 0;
}
