/*
 ID: frceped1
 LANG: C
 TASK: gift1
 */

#include <stdio.h>
#include <strings.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("gift1.in", "r", stdin); freopen("gift1.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXPEOPLE 10
#define BUFSIZE 50

int startingMoney[MAXPEOPLE];
int remainingMoney[MAXPEOPLE];
int receivedMoney[MAXPEOPLE];
char names[MAXPEOPLE][BUFSIZE];
int peopleCount;

int getIndex(char *str);
int getIndex(char *str){
	int i;
	for (i = 0; i < peopleCount; i++) {
		if (strcmp(str, names[i]) == 0) {
			return i;
		}
	}
	return -1; // shut up, compiler!
}

int main(void) {
	int i;
	
	openFiles();
	
	scanf("%d%*[\n]", &peopleCount);
	
	for (i = 0; i < peopleCount; i++)
		scanf("%s", names[i]);
	
	for (i = 0; i < peopleCount; i++) {
		char giver[BUFSIZE];
		scanf("%s", giver);
		
		int index;
		index = getIndex(giver);
		
		int howMany;
		scanf("%d %d%*[\n]", &startingMoney[index], &howMany);
		
		int willGive = !howMany ? 0 : startingMoney[index] / howMany;
		remainingMoney[index] = startingMoney[index] - willGive * howMany;
		
		while (howMany--) {
			char receive[BUFSIZE];
			scanf("%s", receive);
			int newIndex = getIndex(receive);
			receivedMoney[newIndex] += willGive;
		}
	}
	
	for (i = 0; i < peopleCount; i++)
		printf("%s %d\n", names[i], (remainingMoney[i] + receivedMoney[i]) - startingMoney[i]);
	
	return 0;
}

