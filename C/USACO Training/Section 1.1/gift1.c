/*
 ID: frceped1
 LANG: C
 TASK: TASKNAME
 */

#include <stdio.h>

#define UPLOAD 0

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("TASKNAME.in", "r"); out = fopen("TASKNAME.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload header

#include <strings.h>

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

int main(int argc, const char * argv[])
{
	int i;
	
	openFiles();
	
	read("%d%*[\n]", &peopleCount);
	
	for (i = 0; i < peopleCount; i++) {
		getLine(names[i]);
		names[i][strlen(names[i])-1] = '\0';
	}
	
	for (i = 0; i < peopleCount; i++) {
		char giver[BUFSIZE];
		getLine(giver);
		giver[strlen(giver)-1] = '\0';
		
		int index;
		index = getIndex(giver);
		
		int howMany;
		read("%d %d%*[\n]", &startingMoney[index], &howMany);
		
		int willGive = !howMany ? 0 : startingMoney[index] / howMany;
		remainingMoney[index] = startingMoney[index] - willGive * howMany;
		
		while (howMany--) {
			char receive[BUFSIZE];
			getLine(receive);
			receive[strlen(receive)-1] = '\0';
			int newIndex = getIndex(receive);
			receivedMoney[newIndex] += willGive;
		}
	}
	
	for (i = 0; i < peopleCount; i++) {
		print("%s %d\n", names[i], (remainingMoney[i] + receivedMoney[i]) - startingMoney[i]);
	}
	
	return 0;
}

