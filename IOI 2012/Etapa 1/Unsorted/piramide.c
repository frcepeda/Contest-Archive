#include <stdio.h>
#include <stdlib.h>

#define updateMax(a, b) if (b > a) a = b

typedef struct {
    int height, imp;
    int bHeight, bInd;
} Elem;

typedef struct {
    int right, left;
} Vals;

Elem list[1000000];
Vals vals[1000000];
int num;

int main(){
    int i;

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%d %d", &list[i].height, &list[i].imp);
    }

    for(i = 0; i < num; i++){
        int max = list[i].imp;
        int curr = i;
        while(curr > 0){
            if(list[curr].height <= list[curr - 1].height){
                updateMax(list[curr].imp, list[curr - 1].imp);
                curr--;
            } else {
                list[curr].bHeight = list[curr - 1].height;
                list[curr].bInd = curr - 1;
                break;
            }
        }
    }

    return 0;
}
