/*
    ID: frceped1
    LANG: C
    TASK: prefix
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("prefix.in", "r", stdin); freopen("prefix.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define CHLDNUM 4
#define MAXNODES 4000
#define MAXSTRINGS 210

typedef struct _node {
	struct _node *fall, *next, *parent;
       	struct _linkedlist *match;
	struct _node *children[CHLDNUM];
	char c;
	int len;
	bool isEnd;
} node;

typedef struct _linkedlist {
	struct _linkedlist *next;
	node *match;
} linkedlist;

linkedlist matches[MAXSTRINGS];
int nextMatchString;

linkedlist* lolAllocList(node *match){
	matches[nextMatchString].match = match;
	return &matches[nextMatchString++];
}

node lolAllocMemory[MAXNODES];
int lolAllocCount;

node *lolAlloc(void){
	return &lolAllocMemory[lolAllocCount++];
}

node *findChild(node *n, char c){
	node *curr;
	for (curr = n->children[c%CHLDNUM]; curr != NULL; curr = curr->next)
		if (curr->c == c)
			return curr;
	return NULL;
}

node *addChild(node *n, char c){
	node *new = lolAlloc();
	new->c = c;
	new->parent = n;
	new->next = n->children[c%CHLDNUM];
	n->children[c%CHLDNUM] = new;
	return new;
}

node *root;

void _addString(node *n, char *str, int len){
	if (!*str){
		n->match = lolAllocList(n);
		n->isEnd = true;
		n->len = len;
		return;
	}

	node *next = findChild(n, *str);

	if (next == NULL){
		next = addChild(n, *str);
	}

	_addString(next, str+1, len+1);
}

#define addString(str) _addString(root, str, 0);

node *queue[30000];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

void buildAhoCorasick(void){
	node *curr, *next;
	int i;

	push(root);
	root->fall = root;

	while (queueIsNotEmpty){
		curr = pop();

		for (i = 0; i < CHLDNUM; i++){
			next = curr->children[i];
			while (next != NULL){
				push(next);
				next = next->next;
			}
		}

		if (curr == root)
			continue;

		curr->fall = curr->parent->fall;

		while (curr->fall != root && findChild(curr->fall, curr->c) == NULL)
			curr->fall = curr->fall->fall;

		curr->fall = findChild(curr->fall, curr->c);

		if (curr->fall == NULL || curr->fall == curr)
			curr->fall = root;

		if (curr->match)
			curr->match->next = curr->fall->match;
		else
			curr->match = curr->fall->match;
	}
}

bool dp[200010] = {true};
int best = 0;

int main(void){
	openFiles();

	char str[200010];
	int i = 0, last = 0;

	root = lolAlloc();

	while ((str[i++] = getchar()) != '.');

	str[i-1] = '\0';

	for (i = 0; str[i]; i++){
		if (!isalpha(str[i])){
			str[i++] = '\0';
			addString(str+last);
			last = i;
		}
	}

	buildAhoCorasick();

	int len = 1;
	char c;
	while ((c = getchar()) != EOF){
		if (isalpha(c))
			str[len++] = c;
	}
	str[len] = '\0';

	node *curr = root;
	for (i = 1; str[i]; i++){
		const char c = str[i];

		while (curr != root && findChild(curr, c) == NULL)
			curr = curr->fall;

		curr = findChild(curr, c);

		if (curr == NULL)
			curr = root;

		linkedlist *matches = curr->match;

		while (matches != NULL){
			dp[i] |= dp[i - matches->match->len];
			matches = matches->next;
		}

		if (dp[i])
			best = i;
	}

	printf("%d\n", best);

	return 0;
}
