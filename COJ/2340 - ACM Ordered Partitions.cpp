// Accepted
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 100

char str[MAXN];
char output[MAXN];

int main() {
	while (scanf(" %s", str) != EOF){
		int T, N = strlen(str);
		scanf(" %d", &T);
		
		sort(str, str+N);
		output[N] = '\0';
		
		printf("\n");
		while (T--){
			for (int i = 0; i < N; i++){
				int j;
				scanf(" %d", &j);
				output[j-1] = str[i];
			}
			printf("%s\n", output);
		}
	}
}
