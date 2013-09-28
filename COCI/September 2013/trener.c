// 50/50 points

#include <stdio.h>
#include <stdbool.h>

char str[50];
int count[300];
int N;

int main(void){
	int i;

	scanf("%d", &N);

	while (N--){
		scanf("%s", str);
		count[str[0]]++;
	}

	bool didSomething = false;
	for (i = 'a'; i <= 'z'; i++){
		if (count[i] >= 5){
			printf("%c", (char)i);
			didSomething = true;
		}
	}

	if (!didSomething)
		printf("PREDAJA");
	putchar('\n');

	return 0;
}
