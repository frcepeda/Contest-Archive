#include <stdio.h>
#include <ctype.h>

int cost[] = {['A'] = 3, ['B'] = 3, ['C'] = 3, ['D'] = 4, ['E'] = 4, ['F'] = 4,
['G'] = 5, ['H'] = 5, ['I'] = 5, ['J'] = 6, ['K'] = 6, ['L'] = 6, ['M'] = 7, ['N'] = 7,
['O'] = 7, ['P'] = 8, ['Q'] = 8, ['R'] = 8, ['S'] = 8, ['T'] = 9, ['U'] = 9, ['V'] = 9,
['W'] = 10, ['X'] = 10, ['Y'] = 10, ['Z'] = 10};
char str[20];
int answer;

int main(void){
	int i;

	scanf("%s", str);

	for (i = 0; isupper(str[i]); i++)
		answer += cost[(int)str[i]];

	printf("%d\n", answer);

	return 0;
}
