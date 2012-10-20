#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool shoulddelete[100];
char *deletechars = "CAMBRIDGE";

int main(void){
	char c;
	int i;

	for (i = 0; deletechars[i]; i++)
		shoulddelete[(int)deletechars[i]] = true;

	while ((c = getchar()) != EOF)
		if (!shoulddelete[(int)c])
			putchar(c);

	return 0;
}
