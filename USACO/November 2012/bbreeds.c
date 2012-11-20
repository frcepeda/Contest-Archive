#include <stdio.h>
#include <stdbool.h>

#define MAXSTRING 1010

char string[MAXSTRING];
bool visited[1<<23];
int N;

int bitCount(int i){
	int ans;
	for (ans = 0; i; i -= i&-i, ans++);
	return ans;
}

int main(void){
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);

	int i, answer = 0, count[2], j;

	for (N = 0; ; N++){
		string[N] = getchar();
		if (string[N] != ')' && string[N] != '(')
			break;
	}

	if (N > 23){
		printf("0\n");
		return 0;
	}

	for (i = 0; i < (1<<N); i++){
		int c = bitCount(i);
		visited[i] = true;
		if (c % 2 || visited[(~i) & ((1<<N)-1)]) continue;
		count[0] = count[1] = 0;
		for (j = 0; j < N; j++){
			count[!!(i & (1<<j))] += string[j] == '(' ? 1 : -1;
			if (count[0] < 0 || count[1] < 0) break;
		}
		answer += (count[0] == count[1] && count[0] == 0) * 2;
	}

	answer %= 2012;
	printf("%d\n", answer);
	
	return 0;
}
