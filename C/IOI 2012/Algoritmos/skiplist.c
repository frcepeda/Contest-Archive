#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

#define MAXITEMS 1000000
#define MAXMEM 2100000 // A little bit more than 2N, since it's randomized.
#define MAXLEVEL 20 // log2(MAXITEMS)

typedef struct _node {
	struct _node *next, *down;
	int value;
} node;

node POOL[MAXMEM];
int nextpool;

node *released[MAXMEM];
int nextreleased;

void lolfree(node *n){
	released[nextreleased++] = n;
}

node *lolalloc(void){
	if (nextreleased)
		return released[--nextreleased];
	return &POOL[nextpool++];
}

node *newskiplist(void){
	int i;
	node *last = NULL, *nil = lolalloc(), *curr;
	nil->value = INT_MAX;
	for (i = 0; i < MAXLEVEL; i++){
		curr = lolalloc();
		curr->next = nil;
		curr->down = last;
		last = curr;
	}
	return last;
}

node *search(node *n, int value){
	while (n != NULL){
		while (n->next->value <= value)
			n = n->next;
		if (n->value == value && n->down == NULL)
			return n;
		n = n->down;
	}
	return NULL;
}

node *insert(node *n, int value){
	static int level;

	if (n == NULL){
		level = 1;
		while (level <= MAXLEVEL && rand() % 2)
			level++;
		return NULL;
	} else {
		while (n->next->value <= value)
			n = n->next;
		node *down = insert(n->down, value), *new = NULL;
		if (level-- > 0){
			new = lolalloc();
			new->value = value;
			new->down = down;
			new->next = n->next;
			n->next = new;
		}
		return new;
	}
}

void delete(node *n, int value){
	while (n != NULL){
		while (n->next->value < value)
			n = n->next;
		if (n->next->value == value){
			node *deleted = n->next;
			n->next = n->next->next;
			lolfree(deleted);
		}
		n = n->down;
	}
}

int main(void){
	node *skiplist = newskiplist();
	int i;
	srand(time(NULL));
	for (i = 0; i < MAXITEMS; i++)
		insert(skiplist, i);
	for (i = 0; i < MAXITEMS; i++)
		search(skiplist, i);
	for (i = 0; i < MAXITEMS; i++)
		delete(skiplist, i);
	return 0;
}

