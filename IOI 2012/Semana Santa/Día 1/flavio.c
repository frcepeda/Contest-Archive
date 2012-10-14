#include <stdio.h>
#include <ctype.h>

#define MAXLETTER 26

/*           add     subtract   */
int table[MAXLETTER][MAXLETTER];

int max[MAXLETTER][MAXLETTER];
int min[MAXLETTER][MAXLETTER];
int lastsubtract[MAXLETTER][MAXLETTER];

int main(void){
	int i,j;
	int answer = 0;
	char c;

	for (i = 0; i < MAXLETTER; i++)
		for (j = 0; j < MAXLETTER; j++)
			min[i][j] = 1<<25;

	while (islower(c = getchar())){
		c -= 'a';
		for (i = 0; i < MAXLETTER; i++){
			if (c == i) continue; /* skip pairs formed with the same letter */

			if (lastsubtract[i][c] < min[i][c])
				min[i][c] = lastsubtract[i][c];
			lastsubtract[i][c] = --table[i][c];

			table[c][i]++;
			if (table[c][i] - min[c][i] > max[c][i])
				max[c][i] = table[c][i] - min[c][i];
		}
	}

	for (i = 0; i < MAXLETTER; i++)
		for (j = 0; j < MAXLETTER; j++)
			if (answer < max[i][j]) answer = max[i][j];

	printf("%d\n", answer);

	return 0;
}

