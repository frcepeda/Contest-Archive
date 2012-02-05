#include <stdio.h>

#define MAXNUM 1000010
#define TEST 0

typedef struct {
    int next, val;
} Elem;

typedef struct {
    int start, end;
} Range;

Elem over[MAXNUM];
Elem below[MAXNUM];
int nextOv, nextBl, num, count;
int startOv[MAXNUM];
int startBl[MAXNUM];
int lastOv[MAXNUM];
int lastBl[MAXNUM];
int moves[MAXNUM];
int addedToMoves[MAXNUM];
int belowNew[MAXNUM];
Range belowRange[MAXNUM];
int overCount[MAXNUM];
int removed[MAXNUM];
int removedCount;

int ind;

void sort(int arr[], int);

void sort(int arr[], int num){
#define parent(a) ((a)-1)/2
#define childA(a) (a)*2+1
#define childB(a) (a)*2+2
#define swap(a,b) int temp = a; a = b; b = temp
    int last;
    for(last = 0; last < num; last++){
        int curr = last;
        while(parent(curr) >= 0 && arr[parent(curr)] < arr[curr]){
            swap(arr[parent(curr)], arr[curr]);
            curr = parent(curr);
        }
    }
    while(last--){
        swap(arr[0], arr[last]);
        int curr = 0;
        while(curr < last){
            int swapchild;
            if(childA(curr) < last && childB(curr) < last){
                swapchild = arr[childA(curr)] > arr[childB(curr)] ? childA(curr) : childB(curr);
            } else if (childA(curr) < last){
                swapchild = childA(curr);
            } else if (childB(curr) < last) {
                swapchild = childB(curr);
            } else {
                break;
            }
            if(arr[swapchild] > arr[curr]){
                swap(arr[swapchild], arr[curr]);
                curr = swapchild;
            } else {
                break;
            }
        }
    }
#undef parent
#undef childA
#undef childB
#undef swap
}

int main (int argc, const char * argv[])
{
    int i;
    
    scanf("%d %d", &num, &count);
    
    for (i = 0; i <= count; i++) {
        over[i].next = below[i].next = -1;
    }
    
    for (i = 0; i <= num; i++) {
        startOv[i] = startBl[i] = lastOv[i] = lastBl[i] = -1;
    }
    
    for (i = 0; i < count; i++) {
        int nao, overstick, before;
        scanf("%d %d", &nao, &overstick);
        
        //over list
        before = lastOv[overstick];
        if (startOv[overstick] == -1) {
            startOv[overstick] = nextOv;
        } else {
            over[before].next = nextOv;
        }
        lastOv[overstick] = nextOv;
        over[nextOv].val = nao;
        nextOv++;
        overCount[overstick]++;
        
        //below list
        before = lastBl[nao];
        if (startBl[nao] == -1) {
            startBl[nao] = nextBl;
        } else {
            below[before].next = nextBl;
        }
        lastBl[nao] = nextBl;
        below[nextBl].val = overstick;
        nextBl++;
    }
    
    // Rebuild below list
    int last = 0;
    for (i = 1; i <= num; i++) {
        belowRange[i].start = last;
        int curr = startBl[i];
        while (curr != -1) {
            belowNew[last++] = below[curr].val;
            curr = below[curr].next;
        }
        belowRange[i].end = last;
    }
    
#if TEST
    printf("\nOVER\n");
    for (i = 1; i <= num; i++) {
        int curr = startOv[i];
        if (curr == -1) {
            printf("#%d: NONE\n", i);
            continue;
        }
        printf("#%d: ", i);
        while (curr != -1) {
            printf("%d ", over[curr].val);
        curr = over[curr].next;
            }
        printf("\n");
    }
    printf("\nBELOW\n");
    for (i = 1; i <= num; i++) {
        int curr = startBl[i];
        if (curr == -1) {
            printf("#%d: NONE\n", i);
            continue;
        }
        printf("#%d: ", i);
        while (curr != -1) {
            printf("%d ", below[curr].val);
            curr = below[curr].next;
        }
        printf("\n");
    }
    printf("\nOVER COUNT\n");
    for (i = 1; i <= num; i++) {
        printf("#%d: %d\n", i, overCount[i]);
    }
    printf("\n\n");
#endif
    
    for (i = 1; i <= num; i++) {
        if (overCount[i] == 0) {
            moves[ind++] = i;
        }
    }
    
    while (num - ind) {
        static int pending = 0;
        for (i = 0; i < removedCount; i++) {
            int j, nao = removed[i];
            for (j = belowRange[nao].start; j < belowRange[nao].end; j++){
                if (overCount[belowNew[j]] == 0) {
                    if (addedToMoves[belowNew[j]] == 0) {
                        moves[ind++] = belowNew[j];
                        addedToMoves[belowNew[j]] = 1;
                    }
                }
            }
        }
        removedCount = 0;
        if (ind - pending == 0) {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        sort(&moves[pending], ind - pending);
        while (pending < ind) {
            int toRemove = moves[pending];
            for (i = belowRange[toRemove].start; i < belowRange[toRemove].end; i++) {
                overCount[belowNew[i]]--;
            }
            removed[removedCount++] = toRemove;
            overCount[toRemove] = -1;
            pending++;
        }
    }
    
    for (i = 0; i < num; i++) {
        printf("%d\n", moves[i]);
    }
    
    return 0;
}

