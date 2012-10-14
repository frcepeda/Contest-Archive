#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 100000

#define parent(a) (a-1)/2
#define childA(a) a*2+1
#define childB(a) a*2+2

int count;
int boys[MAXNUM];
int girls[MAXNUM];
int nonb[MAXNUM];
int nong[MAXNUM];

void sort(int arr[]){
    int last;
    for(last = 0; last < count; last++){
        int curr = last;
        while(parent(curr) && arr[parent(curr)] < arr[curr]){
            int temp = arr[parent(curr)];
            arr[parent(curr)] = arr[curr];
            arr[curr] = temp;
            curr = parent(curr);
        }
    }
    while(last){
        last--;
        int temp = arr[0];
        arr[0] = arr[last];
        arr[last] = temp;
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
                temp = arr[swapchild];
                arr[swapchild] = arr[curr];
                arr[curr] = temp;
                curr = swapchild;
            } else {
                break;
            }
        }
    }
}

int main()
{
    scanf("%d", &count);
    int i;
    for(i = 0; i < count; i++){
        scanf("%d", &boys[i]);
    }
    for(i = 0; i < count; i++){
        scanf("%d", &girls[i]);
    }
    sort(boys);
    sort(girls);
    printf("%d", count);
    return 0;
}
