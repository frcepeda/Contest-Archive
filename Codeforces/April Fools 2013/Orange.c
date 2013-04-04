#include <stdio.h>
#include <ctype.h>
#include <strings.h>

#define MAXSTRING 55

char string[MAXSTRING];
int len;
int limit;

int main(void){
	int i;

	scanf("%s", string);
	scanf("%d", &limit);

	len = strlen(string);

	for (i = 0; i < len; i++)
		string[i] = tolower(string[i]);

	for (i = 0; i < len; i++)
		if (string[i] < limit + 97)
			string[i] = toupper(string[i]);

	printf("%s\n", string);

	return 0;
}
