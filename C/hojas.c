#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chA, chB, val;
} elem;

elem tree[1000];
int num, ind = 1;
int list[1000];

void insert(int n){
    int curr = 0;

    while(tree[curr].chA != 0 || tree[curr].chB != 0){
        if(tree[curr].chA != 0 && tree[curr].chB != 0){
            if(n < tree[curr].val){
                curr = tree[curr].chA;
            } else {
                curr = tree[curr].chB;
            }
        } else if(tree[curr].chA != 0) {
            if(n < tree[curr].val){
                curr = tree[curr].chA;
            } else {
                break;
            }
        } else if(tree[curr].chB != 0) {
            if(n > tree[curr].val){
                curr = tree[curr].chB;
            } else {
                break;
            }
        }
    }

    if(n < tree[curr].val){
        tree[curr].chA = ind;
    } else {
        tree[curr].chB = ind;
    }

    tree[ind++].val = n;
}

void printTree(int n){
    printf("%d ", tree[n].val);
    if(tree[n].chA != 0){
        printTree(tree[n].chA);
    }
    if(tree[n].chB != 0){
        printTree(tree[n].chB);
    }
}

int main(){
    int i;

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%d", &list[i]);
    }

    tree[0].val = list[num - 1];

    for(i = num - 2; i >= 0; i--){
        insert(list[i]);
    }

    printTree(0);

    return 0;
}
