#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAXSTR 30000010

char pattern[MAXSTR];
char string[MAXSTR];

int plen, slen;

int count[30];
unsigned long long int answer;

int main(void){
	int i, p;

	scanf("%s", pattern);
	scanf("%s", string);

	plen = strlen(pattern);
	slen = strlen(string);

	for (i = 0; i < slen - plen; i++)
		count[string[i] - 'a']++;

	for (p = 0; p < plen; p++, i++){
		if (p > 0)
			count[string[p-1] - 'a']--;
		count[string[i] - 'a']++;
		answer += count[pattern[p] - 'a'];
	}

	/*
	for (i = 0; i < slen; i++)
		if (i + plen <= slen)
			for (p = 0; p < plen; p++)
				if (pattern[p] == string[i+p])
					answer--;
					*/

	printf("%llu\n", answer);

	return 0;
}
