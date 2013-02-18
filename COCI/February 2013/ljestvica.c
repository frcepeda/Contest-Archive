#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int notes[100] = {['C'] = 1, ['F'] = 1, ['G'] = 1, ['A'] = 2, ['D'] = 2, ['E'] = 2};
int count[3];
char str[110]; int len;

int main(void){
	int i;
	bool newSegment = true;

	do
		str[len++] = getchar();
	while (isalpha(str[len-1]) || str[len-1] == '|');
	str[--len] = '\0';

	for (i = 0; i < len; i++){
		if (newSegment){
			count[notes[str[i]]]++;
			newSegment = false;
		} else if (str[i] == '|')
			newSegment = true;
	}

	if (count[1] > count[2] || (count[1] == count[2] && str[len-1] == 'C'))
		printf("C-dur\n");
	else
		printf("A-mol\n");

	return 0;
}
