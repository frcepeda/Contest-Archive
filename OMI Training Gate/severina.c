#include <stdio.h>
#include <stdbool.h>
#include <strings.h>

#define MOD 1337377
#define MAXTRIE 100*4000*3
#define MAXTMP 110
#define MAXSTR 300010

typedef struct _node {
	struct _node *children[27];
	bool isEnd;
} node;

node mem[MAXTRIE];
int nextMem = 1;

node *lolAlloc(void){
	return &mem[nextMem++];
}

node *root = &mem[0];

int dp[MAXSTR];

char str[MAXSTR];
char tmp[MAXTMP];

void insert(node *n, char *s){
	int c = *s-'a';

	if (!*s){
		n->isEnd = true;
		return;
	}

	if (n->children[c] == NULL)
		n->children[c] = lolAlloc();

	insert(n->children[c], s+1);
}

int main(void){
	int i, j, N, ans = 0;

	scanf("%s", str);

	scanf("%d", &N);

	while (N--){
		scanf("%s", tmp);
		insert(root, tmp);
	}

	N = strlen(str);

	dp[N] = true;
	for (i = N-1; j = i, i >= 0; i--){
		node *curr = root;
		while (curr != NULL && j < N){
			curr = curr->children[str[j++]-'a'];
			if (curr != NULL && curr->isEnd)
				dp[i] = (dp[i] + dp[j]) % MOD;
		}
	}

	printf("%d\n", dp[0]);

	return 0;
}
