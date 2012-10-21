#include <stdio.h>

#define MAXCURRENCIES 300+1
#define MAXEXCHANGES 10000
#define MAXHEAP 800000

typedef struct {
    float val;
    int currency;
} Step;

typedef struct {
    int next, val;
	float exchange;
} List;

Step heap[MAXHEAP];
int nextHeap, currencies;

#define stackIsNotEmpty nextHeap

#define parent(a) (((a)-1)/2)
#define childA(a) ((a)*2+1)
#define childB(a) ((a)*2+2)

int visited[MAXCURRENCIES];

List canExchange[MAXCURRENCIES+MAXEXCHANGES];
int nextSpot = MAXCURRENCIES;

Step pop(void);
Step pop(void){
    Step ret = heap[0];
    Step temp = heap[--nextHeap];
    int curr = 0;
    while (childA(curr) < nextHeap || childB(curr) < nextHeap) {
        int swapchild;
        if (childB(curr) >= nextHeap || heap[childA(curr)].val > heap[childB(curr)].val) {
            swapchild = childA(curr);
        } else {
            swapchild = childB(curr);
        }
        if (heap[swapchild].val > temp.val) {
            heap[curr] = heap[swapchild];
            curr = swapchild;
        } else {
            break;
        }
    }
    heap[curr] = temp;
    return ret;
}

float max(float a, float b);
float max(float a, float b){return a > b ? a : b;}

void push(Step new);
void push(Step new){
    int curr = nextHeap++;
    while (curr) {
        if (new.val > heap[parent(curr)].val) {
            heap[curr] = heap[parent(curr)];
            curr = parent(curr);
        } else {
            break;
        }
    }
    heap[curr] = new;
}

float search(int start);
float search(int start){
    Step s = {1, start};
    push(s);
    int i;
    for (i = 1; i <= currencies; i++) {
        visited[i] = 0;
    }
    int first = 1;
    while (stackIsNotEmpty) {
        Step curr = pop();
        if (visited[curr.currency] && curr.currency != start) {
            continue;
        }
        visited[curr.currency] = 1;
        if (!first && curr.currency == start) {
            return curr.val;
        }
        first = 0;
        for (i = curr.currency; i; i = canExchange[i].next) {
            if (canExchange[i].val && (canExchange[i].val == start || !visited[canExchange[i].val])) {
		Step next = {curr.val * canExchange[i].exchange, canExchange[i].val};
                push(next);
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[])
{
    int i;
    scanf("%d %d", &currencies, &i);
    while (i--) {
        int from, to;
        float exch;
        scanf("%d %d %f", &from, &to, &exch);
        int next = from;
        while (canExchange[next].next) {
            next = canExchange[next].next;
        }
        canExchange[nextSpot].val = to;
	canExchange[nextSpot].exchange = exch;
        canExchange[next].next = nextSpot++;
    }
    float ans = -1;
    for (i = 1; i <= currencies; i++) {
        ans = max(ans, search(i));
    }
    printf("%.2f\n", ans);
    return 0;
}

