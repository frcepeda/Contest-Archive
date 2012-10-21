#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y, rad, index;
} Circle;

Circle circles[1080];
int circleCount;

short visited[1080];

int main()
{
    scanf("%d", &circleCount);
    int remaining = circleCount - 1;

    Circle curr;

    int i;
    for(i = 0; i < circleCount; i++){
        scanf("%d %d %d", &circles[i].x, &circles[i].y, &circles[i].rad);
        circles[i].index = i;
        if(circles[i].x == 0 && circles[i].y == 0){
            curr = circles[i];
        }
    }

    while(remaining--){
        visited[curr.index] = 1;
        for(i = 0; i < circleCount; i++){
            if(visited[i] == 0){
                double sum = curr.rad + circles[i].rad;
                int x = abs(curr.x - circles[i].x);
                int y = abs(curr.y - circles[i].y);
                double hypothenuse = sqrt(pow(x, 2) + pow(y, 2));
                if(hypothenuse == sum){
                    curr = circles[i];
                    break;
                }
            }
        }
    }

    printf("%d %d", curr.x, curr.y);

    return 0;
}
