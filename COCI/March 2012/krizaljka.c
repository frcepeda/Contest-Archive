#include <stdio.h>
#include <string.h>

#define MAXSTRING 30

void delNewline(char *str){
	int i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str[i] = '\0';
}

char output[MAXSTRING][MAXSTRING];

int main(int argc, const char * argv[])
{
	int x, y, i;
	char strA[MAXSTRING], strB[MAXSTRING];
	scanf("%s %s", strA, strB);
	delNewline(strA);
	delNewline(strB);
	for (x = 0; x < strlen(strA); x++){
		for (y = 0; y < strlen(strB); y++){
			if (strA[x] == strB[y])
				goto out;
		}
	}	
out:
	for (i = 0; i < strlen(strA); i++)
		output[i][y] = strA[i];
	for (i = 0; i < strlen(strB); i++)
		output[x][i] = strB[i];
	for (y = 0; y < strlen(strB); y++){
		for (x = 0; x < strlen(strA); x++)
			printf("%c", output[x][y] ? output[x][y] : '.');
		printf("\n");
	}
	return 0;
}

