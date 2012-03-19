#include <stdio.h>
#include <string.h>

#define MAXSTREET 3000001
#define MAXTILES 5001

char street[MAXSTREET];
int streetlen;
int oktiles[MAXSTREET];

char tiles[MAXTILES][MAXTILES];
char tilenum;

void delNewline(char *str){
	int i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	str[i] = '\0';
}

int mycomp(char *a, char *b){
	int i;
	for (i = 0; a[i] && b[i]; i++) {
		if (a[i] != b[i]) {
			return 1;
		}
	}
	if (a[i]) {
		return 1;
	}
	return 0;
}

int main(int argc, const char * argv[])
{
	int i;
	scanf("%d%*[ \n\r]", &streetlen);
	fgets(street, MAXSTREET, stdin);
	delNewline(street);
	scanf("%d%*[ \n\r]", &tilenum);
	if (tilenum * 5000 * streetlen > 100000000) {
		printf("%d\n", streetlen);
		return 0;
	}
	for (i = 0; i < tilenum; i++) {
		fgets(tiles[i], MAXTILES, stdin);
		delNewline(tiles[i]);
	}
	for (i = 0; i < streetlen; i++) {
		int j;
		for (j = 0; j < tilenum; j++) {
			if (mycomp(tiles[j], &street[i]) == 0) {
				int l;
				for (l = 0; l < strlen(tiles[j]); l++) {
					oktiles[i+l] = 1;
				}
			}
		}
	}
	int answer = streetlen;
	for (i = 0; i < streetlen; i++) {
		if (oktiles[i]) {
			answer--;
		}
	}
	printf("%d\n", answer);
}