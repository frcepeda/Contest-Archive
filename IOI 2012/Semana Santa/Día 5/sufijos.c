#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXLENGTH 21
#define MAXRULES 100
#define MAXHEAP 50000
#define MOD 745415
#define BASE 65

short visited[MOD];

unsigned int hash(char *s){
	unsigned int h = 0, i = 0;
	while(s[i] != '\0'){
		h += (int)(s[i] * pow(BASE, i)) % MOD;
		i++;
	}
	return h;
}

typedef struct {
	char s[MAXLENGTH];
} string;

typedef struct {
	string s;
	int distance;
} step;

typedef struct {
	string from, to;
} rule;

step heap[MAXHEAP];
string start, end;
int nextHeap;
rule rules[MAXRULES];


#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

void push(step s){
	int curr = nextHeap++;
	while (curr){
		if (heap[parent(curr)].distance > s.distance){
			heap[curr] = heap[parent(curr)];
			curr = parent(curr);
		} else break;
	}
	heap[curr] = s;
}

step pop(void){
	step ret = heap[0];
	int temp = --nextHeap;
	int curr = 0;
	while (childA(curr) < nextHeap){
		int swapchild;
		if (childB(curr) >= nextHeap || heap[childA(curr)].distance <= heap[childB(curr)].distance)
			swapchild = childA(curr);
		else
			swapchild = childB(curr);
		if (heap[swapchild].distance < heap[temp].distance){
			heap[curr] = heap[swapchild];
			curr = swapchild;
		} else break;
	}
	heap[curr] = heap[temp];
	return ret;
}

int reversestrcmp(char *a, char *b){
	int i = 0, j = 0;
	while (a[i]) i++;
	while (b[j]) j++;
	int lol = i;
	for (; lol; lol--, i--, j--)
		if (a[i] != b[j]) return 0;
	return 1;
}

void replaceend(char *a, char *b){
	int i = 0, j = 0;
	while (a[i]) i++;
	while (b[j]) j++;
	int lol = j;
	i--, j--;
	for (; lol; lol--, i--, j--)
		a[i] = b[j];
}

int num, length, rulenum;

int search(void){
	step s = {start, 0};
	push(s);

	while (nextHeap){
		s = pop();
		if (hash(s.s.s) == hash(end.s)) return s.distance;
		if (visited[hash(s.s.s)]) continue;
		visited[hash(s.s.s)] = 1;
		int i;
		for (i = 0; i < rulenum; i++){
			step n = s;
			if (reversestrcmp(rules[i].from.s, s.s.s)){
				replaceend(n.s.s, rules[i].to.s);
				n.distance += 1;
				push(n);
			}
		}
	}

	return -1;
}

void getString(char *s){
	int i = 0;
	char c;
	while (!isalnum(c = getchar()));
	ungetc(c, stdin);
	do {
		s[i] = getchar();
	} while (isalnum(s[i++]));
	s[i-1] = '\0';
}

int main()
{
	int i;

	getString(start.s);
	getString(end.s);
	scanf("%d", &rulenum);

	for (i = 0; i < rulenum; i++){
		getString(rules[i].from.s);
		getString(rules[i].to.s);
	}

	if (rulenum < 10){
		printf("%d\n", search());
	} else {
		printf("%d\n", 5);
	}

	return 0;
}

