#include <stdio.h>

#define MAXWIDTH 1000
#define MAXSTATES 5
#define MAXWINDOWSINROW 100
#define WINDOWWIDTH 5
#define WINDOWHEIGHT 5

int width, height;
char row[WINDOWHEIGHT][MAXWIDTH];

int answers[MAXSTATES];

void readRow(void){
	int i, j;

	for (i = 0; i < WINDOWHEIGHT; i++)
		scanf("%s", row[i]);

	int used[MAXWINDOWSINROW];
	for (i = 0; i < width; i++) used[i] = 0;

	for (i = WINDOWHEIGHT-1; i > 0; i--){
		for (j = 0; j < width; j++){
			if (used[j]) continue;
			int pos = j*WINDOWWIDTH + 1;
			if (row[i][pos] == '*'){
				answers[i]++;
				used[j] = 1;
			}
		}
	}

	for (i = 0; i < width; i++)
		if (!used[i])
			answers[0]++;
}

int main(void){
	int i;

	scanf("%d %d\n", &height, &width);

	for (i = 0; i < height; i++){
		readRow();
	}

	for (i = 0; i < MAXSTATES; i++){
		printf("%d%s", answers[i], i != MAXSTATES - 1 ? " ": "\n");
	}

	return 0;
}

