#include <stdio.h>

#define parent(a) (a-1)/2
#define childA(a) (a*2)+1
#define childB(a) (a*2)+2

#define swap(a,b) int temp = a; a = b; b = temp

#define updateMin(a) if (a < min) min = a

void sort(void);
int test(int);

int house[10];
int houseNum, routerNum;

int heapCount;

void sort(){
    int i;
    for (i = 0; i < houseNum; i++) {
        int curr = i;
        while (curr != 0) {
            if (house[curr] > house[parent(curr)]) {
                swap(house[curr], house[parent(curr)]);
                curr = parent(curr);
            } else {
                break;
            }
        }
    }
    heapCount = houseNum;
    while (--heapCount) {
        swap(house[0], house[heapCount]);
        int curr = 0;
        while (childA(curr) < heapCount || childB(curr) < heapCount) {
            int swapchild;
            if (childA(curr) < heapCount && childB(curr) < heapCount) {
                if (house[childA(curr)] > house[childB(curr)]) {
                    swapchild = childA(curr);
                } else {
                    swapchild = childB(curr);
                }
            } else if (childA(curr) < heapCount){
                swapchild = childA(curr);
            } else if (childB(curr) < heapCount){
                swapchild = childB(curr);
            }
            if (house[swapchild] > house[curr]) {
                swap(house[swapchild], house[curr]);
                curr = swapchild;
            } else {
                break;
            }
        }
    }
}

int test(int dist){
    int i;
    int last = 0;
    int remainingRouters = routerNum;
    
    for (i = 0; i < houseNum; i++) {
        if (house[i] > last) {
            if (remainingRouters--) {
                last = house[i] + (dist*2);
            } else {
                return 0;
            }
        }
    }
    
    return 1;
}

int main (int argc, const char * argv[])
{
    int i;
    
    scanf("%d %d", &houseNum, &routerNum);
    
    for (i = 0; i < houseNum; i++) {
        scanf("%d", &house[i]);
    }
    
    if (routerNum >= houseNum) {
        printf("0");
        return 0;
    }
    
    sort();
    
    int start = 0, end = 1000000, mid;
    int min = 1000000;
    
    while (start < end) {
        mid = ((start + end) / 2 ) + 1;
        if(test(mid)){
            updateMin(mid);
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    printf("%d", min);
    
    return 0;
}

