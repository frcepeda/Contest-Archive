// Accepted
#include <cstdio>

#define MAXN 2010

int N;
unsigned int bytes[MAXN];
char orig[MAXN], next[MAXN];

int main(){
	int i;

	while (scanf("%d", &N), N){
		for (i = 0; i < N; i++)
			scanf("%x", &bytes[i]);

		scanf("%s", orig);
		scanf("%s", next);
		
		for (i = 0; i < N; i++)
			printf("%02X ", orig[i] == '_' ? bytes[i] : (bytes[i] ^ orig[i] ^ next[i]));
		printf("\n");
	}

}
