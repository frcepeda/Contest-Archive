#include <stdio.h>

#define MAXNUM 100000

typedef struct {
    unsigned int parent, child;
} Link;

int linkNum;
Link links[MAXNUM];

typedef struct {
    int firstChild, lastChild;
    int nextSibling;
    int parent;
    int visited;
    unsigned int id;
} Node;

Node tree[MAXNUM];

void sort(Node arr[], int num);
void sort(Node arr[], int num){
#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)
#define swap(a,b) unsigned int t = a; a = b; b = t
    int i;
    for (i = 0; i < num; i++) {
        int curr = i;
        while (curr != 0 && arr[parent(curr)].id < arr[curr].id) {
            swap(arr[parent(curr)].id, arr[curr].id);
            curr = parent(curr);
        }
    }
    while (num--) {
        swap(arr[0].id, arr[num].id);
        int curr = 0;
        while (childA(curr) < num || childB(curr) < num) {
            int swapchild;
            if (childA(curr) < num && childB(curr) < num) {
                swapchild = arr[childA(curr)].id > arr[childB(curr)].id ? childA(curr) : childB(curr);
            } else if (childA(curr) < num) {
                swapchild = childA(curr);
            } else {
                swapchild = childB(curr);
            }
            if (arr[curr].id < arr[swapchild].id) {
                swap(arr[curr].id, arr[swapchild].id);
                curr = swapchild;
            } else {
                break;
            }
        }
    }
}

int searchIndex(unsigned int id, int hi);
int searchIndex(unsigned int id, int hi){
    int lo = 0;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (id < tree[mid].id) {
            hi = mid - 1;
        } else if (id > tree[mid].id) {
            lo = mid + 1;
        } else {
            return mid;
        }
    }
    lo = 0;
    printf("NOT FOUND\n");
    return 3/lo; // CRASH. :]
}

void insertNode(int parent, int child);
void insertNode(int parent, int child){
    if (tree[parent].lastChild == 0) {
        tree[parent].firstChild = tree[parent].lastChild = child;
    } else {
        tree[tree[parent].lastChild].nextSibling = child;
        tree[parent].lastChild = child;
    }
    tree[child].parent = parent;
}

int stack[MAXNUM];
int sti, lasthi;
#define stackIsNotEmpty sti

void push(int i);
void push(int i){
    stack[sti++] = i;
    lasthi = sti;
}

int pop(void);
int pop(void){
    return stack[--sti];
}

int lastprintind = -1; // index in array of last printed node

void printNum(unsigned int i, int ind);
void printNum(unsigned int i, int ind){
    printf("%u ", i);
    lastprintind = ind;
}

void leaves(void);
void leaves(void){
    int curr;
    while (stackIsNotEmpty){
        curr = pop();
        if (!tree[curr].visited) {
            if (!tree[curr].firstChild) {
                printNum(tree[curr].id, curr);
            }
            tree[curr].visited = 1;
        }
        int temp = curr;
        curr = tree[curr].firstChild;
        while (curr) {
            if (!tree[curr].visited) {
                push(temp);
                push(curr);
                tree[temp].firstChild = tree[curr].nextSibling;
                leaves();
            }
            curr = tree[curr].nextSibling;
        }
    }
}

void printOutline(void);
void printOutline(void){
    int curr = 0;
    //left printf("LEFT\n");
    do {
        push(curr);
        printNum(tree[curr].id, curr);
        tree[curr].visited = 1;
        curr = tree[curr].firstChild;
    } while (curr);
    
    //base printf("\nBASE\n");
    leaves();
    
    //right printf("\nRIGHT\n");
    curr = tree[lastprintind].parent;
    while (curr != 0) {
        printNum(tree[curr].id, curr);
        curr = tree[curr].parent;
    }
}

int main (int argc, const char * argv[])
{
    scanf("%d", &linkNum);
    
    int i;
    
    for (i = 0; i < linkNum; i++) {
        scanf("%d %d", &links[i].parent, &links[i].child);
        tree[i+1].id = links[i].child;
    }
    
    sort(tree, linkNum+1);
    
    for (i = 0; i < linkNum; i++) {
        insertNode(searchIndex(links[i].parent, linkNum), searchIndex(links[i].child, linkNum));
    }
    
    printOutline();
    
    printf("\n");
    
    return 0;
}
