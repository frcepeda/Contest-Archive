#include <stdio.h>
#include <strings.h>

char str[1010];
int N;

int main(void){
	int i, j, l, best = 0;

	scanf("%s", str);
	N = strlen(str);

	for (i = 0; i < N; i++){
		int curr = 1;
		l = i;

		for (j = i+1; j < N; j++){
			if (str[j] == str[i] && (j - l + 1) % 2 == 0){
				l = j;
				curr++;
			}
		}

		if (curr > best) best = curr;
	}

	printf("%d\n", best);

	return 0;
}
