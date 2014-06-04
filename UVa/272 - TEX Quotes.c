// Accepted
#include <stdio.h>

int main(void){
	int first = 1;
	char c;

	while ((c = getchar()) != EOF) {
		if (c != '\"')
			putchar(c);
		else {
			printf("%s", first ? "``" : "''");
			first ^= 1;
		}
	}

	return 0;
}
