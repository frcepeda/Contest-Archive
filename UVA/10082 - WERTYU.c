// Accepted
#include <stdio.h>

char *thingy = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

char map(char c){
	if (c == ' ' || c == '\n') return c;
	char *t = thingy;
	for (; *t != c; t++);
	return *(--t);
}

int main(void) {
	char c;
	while ((c = getchar()) != EOF)
		putchar(map(c));
	return 0;
}
