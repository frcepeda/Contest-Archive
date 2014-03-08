// 50/50 points
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXL 110

int N, L;
char p[MAXL], s[MAXL];

bool match(){
	int slen = strlen(s), i;

	if (slen < L-1) return false;

	for (i = 0; p[i] != '*'; i++)
		if (s[i] != p[i])
			return false;

	for (i = 0; p[L-i-1] != '*'; i++)
		if (p[L-i-1] != s[slen-i-1])
			return false;

	return true;
}

int main(void){
	scanf("%d", &N);
	scanf("%s", p);

	L = strlen(p);

	while (N--){
		scanf("%s", s);
		printf("%s\n", match() ? "DA" : "NE");
	}

	return 0;
}
