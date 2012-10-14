//
//  main.c
//  Santa
//
//  Created by Freddy Roman Cepeda on 12/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#include <strings.h>

#define MAXNUM 1000
#define CUTOFF 26

#define min(a,b) (a < b ? a : b)

typedef struct {
    int val,next;
} Node;

typedef struct {
    int where, gifts;
} Step;

Step makeStep(int w, int s);
Step makeStep(int w, int s){
    Step a = {w,s};
    return a;
}

Step queue[MAXNUM*MAXNUM];
int qptr;

#define queueIsNotEmpty qptr
#define clearQueue() qptr = 0
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define swap(a,b) Step _temp = a; a = b; b = _temp

void push(Step s);
void push(Step s){
    int curr = qptr;
    queue[qptr++] = s;
    while (curr) {
        if (queue[curr].gifts > queue[parent(curr)].gifts) {
            swap(queue[curr], queue[parent(curr)]);
        } else {
            break;
        }
    }
}

Step pop(void);
Step pop(void){
    Step ret = queue[0];
    int curr = 0;
    --qptr;
    swap(queue[0], queue[qptr]);
    while (childA(curr) < qptr || childB(curr) < qptr) {
        int swapchild;
        if (childA(curr) < qptr && childB(curr) < qptr) {
            swapchild = queue[childA(curr)].gifts > queue[childB(curr)].gifts ? childA(curr) : childB(curr);
        } else if (childA(curr) < qptr){
            swapchild = childA(curr);
        } else {
            swapchild = childB(curr);
        }
        if (queue[swapchild].gifts > queue[curr].gifts) {
            swap(queue[swapchild], queue[curr]);
            curr = swapchild;
        } else {
            break;
        }
    }
    return ret;
}

int toInt(char x);
int toInt(char x){
    int val = x;
    if (val >= 65 || val <= 90) {
        return val - 'A';
    }
    return val - 'a' + 26;
}

Node adjacent[MAXNUM*MAXNUM];
int last;
int start[MAXNUM];
int count[MAXNUM];
int visited[MAXNUM];
int sW, gifts, eW;

void add(int a, int b);
void add(int a, int b){
    adjacent[++last].val = b;
    adjacent[last].next = start[a];
    start[a] = last;
    count[a]++;
}

int cost(int a, int where);
int cost(int a, int where){
    if (where >= CUTOFF) {
        return a - 1;
    } else {
        return a - (a / 20) - (a % 20 ? 1 : 0);
    }
}

int doSearch(int giftStart);
int doSearch(int giftStart){
    clearQueue();
    memset(visited, 0, sizeof(visited));
    push(makeStep(sW, giftStart));
    while (queueIsNotEmpty) {
        Step curr = pop();
        int i;
        if (visited[curr.where]) {
            continue;
        }
        visited[curr.where] = 1;
        if (curr.where == eW) {
            return 1;
        }
        for (i = start[curr.where]; i; i = adjacent[i].next) {
            int nextPlace = adjacent[i].val;
            int remaining = cost(curr.gifts, nextPlace);
            if (remaining >= gifts) {
                push(makeStep(nextPlace, remaining));
            }
        }
    }
    return 0;
}

int main (int argc, const char * argv[])
{
    int links, i;
    scanf("%d", &links);
    for (i = 0; i < links; i++) {
        char a, b;
        do {
            a = getchar();
        } while (a == '\n' || a == ' ' || a == '\r');
        do {
            b = getchar();
        } while (b == '\n' || b == ' ' || b == '\r');
        a = toInt(a);
        b = toInt(b);
        add(a,b);
        add(b,a);
    }
    char s, e;
    scanf("%d", &gifts);
    do {
        s = getchar();
    } while (s == '\n' || s == ' ' || s == '\r');
    do {
        e = getchar();
    } while (e == '\n' || e == ' ' || e == '\r');
    sW = toInt(s);
    eW = toInt(e);
    int lo = 0, hi = 2000;
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (doSearch(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d\n", lo);
    return 0;
}

