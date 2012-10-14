/*
    ID: frceped1
    LANG: C
    TASK: dualpal
 */

#include <strings.h>
#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define read(...) fscanf(in, __VA_ARGS__)
	#define print(...) fprintf(out, __VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), in);
	#define openFiles() in = fopen("dualpal.in", "r"); out = fopen("dualpal.out", "w")
#else
	#define read(...) scanf(__VA_ARGS__)
	#define print(...) printf(__VA_ARGS__)
	#define getLine(buf) fgets(buf, sizeof(buf), stdin);
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

void changeToBase(int num, int base, char *buf){
	int i;
	for (i = 0; num; i++){
		buf[i] = digits[num % base];
		num /= base;
	}
}

int isPalindrome(char *s){
	int i = 0, j = strlen(s)-1;
	for (; i <= j; i++, j--)
		if (s[i] != s[j]) return 0;
	return 1;
}

int reverse(char *s){
	int i = 0, j = strlen(s)-1;
	for (; i < j; i++, j--){
		char c;
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

char buf[500];

int main(void){
	openFiles();

	int i, greater;
	read("%d %d", &i, &greater);

	while(i){
		int baseCount = 0, base;
		greater++;
		for (base = 2; base <= 10; base++){
			memset(buf, 0, 500);
			changeToBase(greater, base, buf);
			if (isPalindrome(buf)){
				baseCount++;
				if (baseCount == 2){
					i--;
					print("%d\n", greater);
					break;
				}
			}
		}
	}
	
	return 0;
}
