/*
    ID: frceped1
    LANG: C
    TASK: palsquare
 */

#include <strings.h>
#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("palsquare.in", "r", stdin); freopen("palsquare.out", "w", stdout)
#else
	#define openFiles()
#endif

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
char buf2[500];

int main(void){
	openFiles();

	int base;
	scanf("%d", &base);

	int i;
	for (i = 1; i <= 300; i++){
		changeToBase(i*i, base, buf);
		if (isPalindrome(buf)){
			changeToBase(i, base, buf2);
			reverse(buf2);
			printf("%s %s\n", buf2, buf);
		}
	}
	
	return 0;
}
