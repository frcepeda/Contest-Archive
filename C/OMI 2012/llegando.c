#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 5010
#define MAXM 500010

typedef struct {
    int id, next;
} node;

int start[MAXN];
node nodes[MAXM*2];
int nextNode = 1;

#define addNode(a,b) nodes[nextNode].next = start[a]; start[a] = nextNode; nodes[nextNode++].id = b

int N,M;
int P,K,to;

bool dostuff(int n, int remaining){
    int i;

    if (remaining < 0)
        return false;

    if (remaining == 0 && n == to)
        return true;

    for (i = start[n]; i; i = nodes[i].next){
        node curr = nodes[i];
        if(dostuff(curr.id, remaining-1))
            return true;
    }

    return false;
}

int main(void){
    int i;

    scanf("%d %d", &N, &M);

    for (i = 0; i < M; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        addNode(a,b);
        addNode(b,a);
    }

    scanf("%d", &P);

    while (P--){
        scanf("%d %d", &to, &K);
        printf("%d\n", dostuff(1,K));
    }

    return 0;
}
