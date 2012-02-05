//
//  main.c
//  Skip List
//
//  Created by Freddy Roman Cepeda on 1/13/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

typedef enum {
    node,
    list
} lallocArgs;

typedef struct _node Node;
struct _node {
    Node *next, *down;
    unsigned short childNum;
    int key;
    void *info;
};

typedef struct _skiplist SkipList;
struct _skiplist {
    int maxLevel;
    unsigned int isRandom:1;
    Node *start;
};

#define USESTATICMEM 1

#if USESTATICMEM
#define MAXNODES 1000000
#define MAXLISTS 10
#endif

#if USESTATICMEM
Node nHeap[MAXNODES];
unsigned int nInd;
SkipList sHeap[MAXLISTS];
unsigned int sInd;
#endif

//Public function prototypes
SkipList *makeSkipList(size_t maxSize, int random); //Nonzero for random list
Node *makeNode(void *info, int key);
void insert(SkipList *s, Node *n);
Node *search(SkipList *s, int key); //Returns null if not found
//End

//Utility function prototypes
Node *_insert(SkipList *s, Node *curr, Node *n);
int getLevel(SkipList *s);
void addNode(Node *a, Node *b);
Node *getSplitChild(Node *n);
void *lalloc(lallocArgs args); // LOL Alloc
//End

#define MAXCHILDREN 2

void *lalloc(lallocArgs args){
#if USESTATICMEM
    if (args == node) {
        return &nHeap[nInd++];
    } else if (args == list){
        return &sHeap[sInd++];
    }
#else
    if (args == node) {
        return malloc(sizeof(Node));
    } else if (args == list){
        return malloc(sizeof(SkipList));
    }
#endif
    return NULL;
}

SkipList *makeSkipList(size_t maxSize, int random){
    SkipList *s = lalloc(list);
    s->maxLevel = log2(maxSize);
    s->start = makeNode(NULL, 0);
    s->isRandom = random ? 1 : 0;
    Node *curr = s->start;
    int i;
    for (i = 0; i < s->maxLevel - 1; i++) {
        curr = curr->down = makeNode(NULL, 0);
    }
    return s;
}

Node *makeNode(void *info, int key){
    Node *n = lalloc(node);
    n->key = key;
    n->info = info;
    n->next = n->down = NULL;
    n->childNum = 0;
    return n;
}

Node *search(SkipList *s, int key){
    Node *curr = s->start;
    while (curr) {
        if (!curr->down && curr->key == key) {
            return curr;
        }
        if (!curr->next || curr->next->key > key){
            curr = curr->down;
        } else {
            curr = curr->next;
        }
    }
    return NULL;
}

int getLevel(SkipList *s){
    int level = 0;
    for (;level < s->maxLevel && rand() > RAND_MAX/2; level++);
    return level;
}

Node *getSplitChild(Node *n){
    int i;
    n = n->down;
    for (i = 0; i < MAXCHILDREN; i++) {
        n = n->next;
    }
    return n;
}

void addNode(Node *a, Node *b){
    b->next = a->next;
    a->next = b;
}

int level;

Node *_insert(SkipList *s, Node *curr, Node *n){
    Node *newNode = NULL, *returnNode = NULL;
    
    for (;curr->next && curr->next->key < n->key; curr = curr->next);
    
    if (curr->down) {
        returnNode = _insert(s, curr->down, n);
    } else {
        if (s->isRandom) {
            level = getLevel(s);
        }
        addNode(curr, n);
        return n;
    }
    
    if (s->isRandom && level > 0) {
        level--;
        newNode = makeNode(NULL, returnNode->key);
        addNode(curr, newNode);
        newNode->down = returnNode;
    } else if (!s->isRandom && returnNode){
        curr->childNum++;
        if (curr->childNum > MAXCHILDREN) {
            Node *splitChild = getSplitChild(curr);
            newNode = makeNode(NULL, splitChild->key);
            addNode(curr, newNode);
            newNode->down = splitChild;
        }
    }
    
    return newNode;
}

void insert(SkipList *s, Node *n){
    _insert(s, s->start, n);
}

int main (int argc, const char * argv[])
{
    SkipList *s = makeSkipList(10, 0);
    srand((unsigned int)time(NULL));
    insert(s, makeNode((void *)1234, 1));
    insert(s, makeNode((void *)2345, 2));
    insert(s, makeNode((void *)3456, 3));
    insert(s, makeNode((void *)4567, 4));
    insert(s, makeNode((void *)5678, 5));
    printf("%d\n", (int)search(s, 3)->info);
    return 0;
}
