#include <stdio.h>
#include <stdbool.h>

#define MAXDIG 7

int N;
int base[MAXDIG] = {1, 20, 360};

int getDigit(void){
	bool readSomething = false;
	char c;
	int ret = 0;

	while ((c = getchar()) != '\n' || !readSomething){
		if (c == '.'){
			ret++;
			readSomething = true;
		} else if (c == '-'){
			ret += 5;
			readSomething = true;
		} else if (c == 'S')
			return 0;
	}

	return ret;
}

int main(void){
	int i;

	for (i = 3; i < MAXDIG; i++)
		base[i] = base[i-1] * 20;

	while (scanf("%d", &N), N){
		int answer = 0;

		for (i = N-1; i >= 0; i--)
			answer += getDigit() * base[i];

		printf("%d\n", answer);
	}
}
