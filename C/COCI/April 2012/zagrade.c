#include <stdio.h>

#define MAXLENGTH 300
#define MAXBRACKETS 15

char expr[MAXLENGTH];

int willUse[MAXBRACKETS];
int bracketCount;

int countBrackets(void){
	int i, count = 0;

	for (i = 0; expr[i]; i++)
		if (expr[i] == '(') count++;

	return count;
}

int bracket;
int printAnswer(int i){
	for (; expr[i]; i++){
		if (expr[i] == '('){
			int shouldPrint = willUse[bracket];
			bracket++;
			if (shouldPrint) putchar(expr[i]);
			i = printAnswer(i+1);
			if (shouldPrint) putchar(expr[i]);
		} else if (expr[i] == ')') break;
		else putchar(expr[i]);
	}
	return i;
}

int first = 1;

void doStuff(int pos){
	if (pos < bracketCount){
		willUse[pos] = 1;
		doStuff(pos+1);
		willUse[pos] = 0;
		doStuff(pos+1);
	} else {
		if (first){
			first = 0;
			return;
		}
		bracket = 0;
		printAnswer(0);
		putchar('\n');
	}
}

int main(void){
	scanf("%s", expr);

	bracketCount = countBrackets();

	doStuff(0);

	return 0;
}

