//
//  main.c
//  Pavo
//
//  Created by Freddy Roman Cepeda on 12/25/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define POINTCOUNT 8

#define START 0
#define END 1

typedef struct {
    int x,y;
    int id;
} Point;

#define distanceBetween(a,b) (abs(a.x-b.x)+abs(a.y-b.y))
#define pointsAreEqual(a,b) (a.id == b.id)
#define isPair(a,b) (pairs[a.id] == b.id)

int pairs[POINTCOUNT] = {-1, -1, 3, 2, 5, 4, 7, 6};

Point makePoint(int x, int y, int id);
Point makePoint(int x, int y, int id){
    Point p = {x,y,id};
    return p;
}

typedef struct {
    Point point;
    int time;
} Step;

Step makeStep(Point p, int t);
Step makeStep(Point p, int t){
    Step s = {p,t};
    return s;
}

Point points[POINTCOUNT];
int distances[POINTCOUNT][POINTCOUNT];
int visited[POINTCOUNT];

//------- Heap Implementation

// Change these macros
#define STRUCTTYPE Step
#define MEMBERNAME time
#define MAXHEAPSIZE POINTCOUNT*POINTCOUNT
#define GREATESTFIRST 0 // 1:True, 0:False
// Don't change anything below

#define queueIsNotEmpty _qptr
#define clearQueue() _qptr = 0

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

#if GREATESTFIRST == 1
    #define COMPARISONOP >
#else
    #define COMPARISONOP <
#endif

STRUCTTYPE _heap[MAXHEAPSIZE];
int _qptr;
void push(STRUCTTYPE s);
void push(STRUCTTYPE s){
    int curr = _qptr++;
    while (curr) {
        if (s.MEMBERNAME COMPARISONOP _heap[parent(curr)].MEMBERNAME) {
            _heap[curr] = _heap[parent(curr)];
            curr = parent(curr);
        } else
            break;
    }
    _heap[curr] = s;
}
STRUCTTYPE pop(void);
STRUCTTYPE pop(void){
    STRUCTTYPE ret = _heap[0];
    STRUCTTYPE temp = _heap[--_qptr];
    int curr = 0;
    while (childA(curr) < _qptr || childB(curr) < _qptr) {
        int swapchild;
        if (_heap[childA(curr)].MEMBERNAME COMPARISONOP _heap[childB(curr)].MEMBERNAME || childB(curr) >= _qptr)
            swapchild = childA(curr);
        else (childA(curr) < _qptr)
            swapchild = childB(curr);
        if (_heap[swapchild].MEMBERNAME COMPARISONOP temp.MEMBERNAME) {
            _heap[curr] = _heap[swapchild];
            curr = swapchild;
        } else
            break;
    }
    _heap[curr] = temp;
    return ret;
}

//------- End

int doSearchThing(void);
int doSearchThing(void){
    push(makeStep(points[START], 0));
    while (queueIsNotEmpty) {
        Step curr = pop();
        int i;
        if (visited[curr.point.id]) {
            continue;
        }
        visited[curr.point.id] = 1;
        if (pointsAreEqual(curr.point, points[END])) {
            return curr.time;
        }
        for (i = 0; i < POINTCOUNT; i++) {
            if (!pointsAreEqual(curr.point, points[i]) && !visited[i]) {
                Step next = {points[i], 0};
                if (isPair(curr.point, points[i])) {
                    next.time = curr.time + 10;
                } else {
                    next.time = curr.time + distanceBetween(curr.point, points[i]);
                }
                push(next);
            }
        }
    }
    return -1; //shut the compiler up
}

int main (int argc, const char * argv[])
{
    int i;
    for (i = 0; i < POINTCOUNT; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].id = i;
    }
    printf("%d\n", doSearchThing());
    return 0;
}

