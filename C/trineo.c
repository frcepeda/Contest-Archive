#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define updateMax(i) if(i > max) max = i;

#define swap(a,b) Curve temp = a; a = b; b = temp;

#define parent(a) (a-1)/2
#define childA(a) a*2 + 1
#define childB(a) a*2 + 2

typedef struct {
    int loc, speed;
} Curve;

Curve curves[100003];
int cIndex;

void push(Curve curve){
    curves[cIndex] = curve;
    int n = cIndex++;
    while(n){
        if(curves[parent(n)].loc < curves[n].loc){
            swap(curves[parent(n)], curves[n]);
            n = parent(n);
        } else {
            break;
        }
    }
}

Curve pop(){
    Curve returnC = curves[0];
    cIndex--;
    swap(curves[0], curves[cIndex]);
    int n = 0;
    while(childA(n) <= cIndex - 1 || childB(n) <= cIndex - 1){
        int swapC = -1;
        if(childA(n) <= cIndex - 1 && childB(n) <= cIndex - 1){
            swapC = curves[childA(n)].loc > curves[childB(n)].loc ? childA(n) : childB(n);
        } else if (childA(n) <= cIndex - 1) {
            swapC = childA(n);
        } else {
            swapC = childB(n);
        }
        if(swapC == -1){
            break;
        }
        if(curves[swapC].loc > curves[n].loc){
            swap(curves[n], curves[swapC]);
            n = swapC;
        } else {
            break;
        }
    }
    return returnC;
}


int main()
{
    int trackSize, count;

    scanf("%d %d", &trackSize, &count);

    int max = 0;

    int i;

    for(i = 1; i <= count; i++){
        Curve c;
        scanf("%d %d", &c.loc, &c.speed);
        push(c);
    }

    Curve c = {0, 1};
    push(c);

    c.loc = trackSize;
    c.speed = INT_MAX;
    push(c);

    for(i = cIndex; i >= 0; i--){
        curves[i] = pop();
    }

    for(i = 1; i <= count + 1; i++){
        int currLoc = curves[i].loc;
        int currSpeed = curves[i].speed;
        int n = i + 1;
        int time = curves[n].loc - currLoc;

        int test = -currSpeed + curves[n].speed - time;

        if (test == 0){
            updateMax(curves[n].speed);
        } else if (test > 0) {
            curves[n].speed = currSpeed + time;
            updateMax(curves[n].speed);
        } else if (test < 0) {
            if(currSpeed < curves[n].speed){
                updateMax(currSpeed + (time / 2) + 1);
            } else {
                updateMax(currSpeed + ((time - (currSpeed - curves[i].speed)) / 2));
            }
        }
    }

    printf("%d\n", max);

    return 0;
}
