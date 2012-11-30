/*
    ID: frceped1
    LANG: C
    TASK: heritage
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("heritage.in", "r", stdin); freopen("heritage.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXLEN 30

char preorder[MAXLEN];
char inorder[MAXLEN];

int inorderIdx[MAXLEN];
int where;

void postorder(int idx, int a, int b){
	if (a > b){
		where--;
		return;
	}

	postorder(where++, a, inorderIdx[preorder[idx] - 'A'] - 1);
	postorder(where++, inorderIdx[preorder[idx] - 'A'] + 1, b);
	putchar(preorder[idx]);
}

int main(void){
	openFiles();

	int i;

	scanf("%s", inorder);
	scanf("%s", preorder);

	for (i = 0; inorder[i]; i++)
		inorderIdx[inorder[i] - 'A'] = i;

	postorder(where++, 0, i-1);

	putchar('\n');

	return 0;
}
