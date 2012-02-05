#include <stdio.h>
#include <stdlib.h>

#define updateMax(num) if(num > max) max = num;

typedef struct{
    int num, target;
} Spy;

Spy spies[1000001];
int temp[1000001];
int max;

int main()
{
    int spyCount;
    scanf("%d", &spyCount);
    int i;
    for(i = 1; i <= spyCount; i++){
        scanf("%d", &spies[i].target);
    }
    for(i = 1; i <= spyCount; i++){
        if(spies[i].num){
            continue;
        }
        int curr = i;
        int spied = 0;
        while(spies[curr].num == 0){
            temp[spied++] = curr;
            spies[curr].num = -1;
            curr = spies[curr].target;
        }
        int total;
        if(spies[curr].num == -1){
            total = spied;
            int index;
            for(index = 0; temp[index] != curr; index++){
                spies[temp[index]].num = total - index;
            }
            for(curr = index; curr < spied; curr++){
                spies[temp[curr]].num = total - index;
            }
        } else {
            total = spied + spies[curr].num;
            for(curr = 0; curr < spied; curr++){
                spies[temp[curr]].num = total - curr;
            }
        }
        updateMax(total);
    }
    printf("%d\n", max);
    return 0;
}
