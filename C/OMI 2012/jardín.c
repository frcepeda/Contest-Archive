#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000010
#define MAXMAP 1000000001

typedef struct{
    int pos, idx;
} child;

typedef struct {
    bool dir;
    int idx;
} position_;

int childCmp(const void *ap, const void *bp){
    int a = ((child *)ap)->pos;
    int b = ((child *)bp)->pos;
    if (a > b)
        return 1;
    if (b > a)
        return -1;
    return 0;
}

child children[2][MAXN];
int count[2];
position_ position[MAXN];

int N, Q;

int binsearch(bool dir, int pos){
    int hi = count[dir], lo = 0, mid;
    int best = -1;
    while (lo < hi){
        mid = (hi + lo)/2;
        if (children[dir][mid].pos <= pos){
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return best;
}

int panic(bool dir, int pos){
    int hi = count[dir], lo = 0, mid;
    int best = -1;
    while (lo < hi){
        mid = (hi + lo)/2;
        if (children[dir][mid].pos >= pos){
            best = mid;
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return best;
}

int domagic(int id, int secs){
    bool dir = position[id].dir;
    int idx = position[id].idx;
    int pos = children[dir][idx].pos;
    int nextToMe = dir ? panic(!dir, children[dir][idx].pos) : binsearch(!dir, children[dir][idx].pos);

    int left, right;

    if (dir){
        right = idx-1;
        left = nextToMe;
    } else {
        right = nextToMe;
        left = idx+1;
    }

    int holding = id;
    while (true){
        if (dir){
            if (left < count[0] && left >= 0 && children[0][left].pos + secs >= pos){
                holding = children[0][left].idx;
                left++;
            } else {
                return holding;
            }
        } else {
            if (right < count[1] && right >= 0 && children[1][right].pos - secs <= pos){
                holding = children[1][right].idx;
                right--;
            } else {
                return holding;
            }
        }
        dir = !dir;
    }
}

int main(void){
    int i, dir;

    scanf("%d", &N);

    for (i = 1; i <= N; i++){
        int tmp, dir;
        scanf("%d %d", &tmp, &dir);
        children[dir>0][count[dir>0]].pos = tmp;
        children[dir>0][count[dir>0]].idx = i;
        count[dir>0]++;
    }

    for (i = 0; i < 2; i++)
        qsort(children[i], count[i], sizeof(child), childCmp);

    for (dir = 0; dir < 2; dir++){
        for (i = 0; i < count[dir]; i++){
            position[children[dir][i].idx].dir = dir;
            position[children[dir][i].idx].idx = i;
        }
    }

    scanf("%d", &Q);

    while (Q--){
        char type;
        int id, k;
        do{
            type = getchar();
        } while (type != 'N' && type != 'P');
        scanf("%d %d", &id, &k);
        switch (type){
            case 'P':
                printf("%d\n", children[position[id].dir][position[id].idx].pos + k * (position[id].dir ? 1 : -1));
                break;
            case 'N':
                printf("%d\n", domagic(id, k));
                break;
        }
    }

    return 0;
}
