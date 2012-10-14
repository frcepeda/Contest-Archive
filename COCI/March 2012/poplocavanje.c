#include <stdio.h>
#include <stdbool.h>

#define MAXNODES 25000001
#define MAXSTRING 300001
#define MAXTILE 5001
#define CHILDNUM 4

int max(int a, int b) {
	return a > b ? a : b;
}

typedef struct _node node;
struct _node {
	char c;
	node *children[CHILDNUM]; // trie
	node *next; // for linked list
	node *fall; // when matching fails
	node *parent;
	bool isEnd;
	int length;
};

void addChild(node *curr, node *child){
	node *last = curr->children[child->c % CHILDNUM];

	if (last == NULL){
		curr->children[child->c % CHILDNUM] = child;
	} else {
		while (last->next != NULL)
			last = last->next;

		last->next = child;
	}

	child->parent = curr;
}

node *findChild(node *curr, char c){
	curr = curr->children[c % CHILDNUM];

	while (curr != NULL){
		if (curr->c == c)
			return curr;
		else
			curr = curr->next;
	}

	return NULL;
}

node storage[MAXNODES];
int nextNode = 1;
node *root = &storage[0];

node *newNode(char c){
	storage[nextNode].c = c;
	return &storage[nextNode++];
}

void addStringToNode(node *curr, char *str, int len){
	char c = *str;

	if (!c){
		curr->isEnd = true;
		curr->length = len;
		return;
	}
	
	node *next = findChild(curr, c);

	if (next == NULL){
		next = newNode(c);
		addChild(curr, next);
	}

	addStringToNode(next, str+1, len+1);
}

void addString(char *str){
	addStringToNode(root, str, 0);
}

node *queue[MAXNODES];
int qs, qe;

#define queueIsNotEmpty qs < qe

void push(node *n){
	queue[qe++] = n;
}

node *pop(void){
	return queue[qs++];
}

void constructAhoCorasick(void){
	int i;

	root->fall = root;
	push(root);

	while(queueIsNotEmpty) {
		node *curr = pop();

		for (i = 0; i < CHILDNUM; i++){
			node *child = curr->children[i];
			while (child != NULL){
				push(child);
				child = child->next;
			}
		}

		if (curr == root) continue;

		node *fall = curr->parent->fall;

		while (fall != root && findChild(fall, curr->c) == NULL)
			fall = fall->fall;

		curr->fall = findChild(fall, curr->c);

		if (curr->fall == NULL || curr->fall == curr)
			curr->fall = root;
	}
}

int tiled[MAXSTRING];

void tile(int start, int length){
	int i = start-length+1;
	for (; i <= start; i++)
		tiled[i] = true;
}

void searchInString(char *str){
	int i;
	char c;
	node *state = root;
	for (i = 0; str[i]; i++){
		c = str[i];

		while (state != root && findChild(state, c) == NULL)
			state = state->fall;

		state = findChild(state, c);

		if (state == NULL){
			state = root;
			continue;
		}

		node *report = state;

		while (report != root){
			if (report->isEnd){
				tiled[i-report->length+1] = max(tiled[i-report->length+1], report->length);
			}
			report = report->fall;
		}
	}
}

int main(void){
	int i;
	char searchString[MAXSTRING];
	char tileString[MAXTILE];

	scanf("%*d");
	scanf("%s", searchString);
	scanf("%d", &i);

	while (i--){
		scanf("%s", tileString);
		addString(tileString);
	}

	constructAhoCorasick();

	searchInString(searchString);

	int answer = 0;
	for (i = 0; searchString[i]; i++){
		if (!tiled[i])
			answer++;
		else
			i += tiled[i];
	}

	printf("%d\n", answer);

	return 0;
}

