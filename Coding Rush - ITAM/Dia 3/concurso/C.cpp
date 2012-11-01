#include <stdio.h>
#include <ctype.h>

int list[] = {0, 1, 6, 4, 3, 9, 2, 8, 7, 5};

int main(){
	char c;
	while ((c = getchar()) != EOF){
		if (isdigit(c))
			c = list[c-'0']+'0';
		putchar(c);
	}
	return 0;
}
