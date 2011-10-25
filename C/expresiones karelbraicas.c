#include <stdio.h>
#include <stdlib.h>

#define inpSize 100000

#define swap(a,b) int temp = a;a=b;b=temp

#define parent(a) (a-1)/2
#define childA(a) (a*2)+1
#define childB(a) (a*2)+2

void sort(void);
void push(int);
int test(int);

int nums[inpSize];
int expr[inpSize];
int stack[inpSize];
int sti;

int expLen;

int numCount;

void push(int i){
    nums[numCount++] = i;
    int curr = numCount - 1;
    while (curr != 0) {
        if (nums[parent(curr)] < nums[curr]) {
            swap(nums[parent(curr)], nums[curr]);
            curr = parent(curr);
        } else {
            break;
        }
    }
}

void sort(){
    int temp = numCount;
    while (numCount) {
        numCount--;
        swap(nums[numCount], nums[0]);
        int curr = 0;
        while (curr < numCount) {
            int swapChild;
            if (childA(curr) < numCount && childB(curr) < numCount) {
                swapChild = nums[childA(curr)] > nums[childB(curr)] ? childA(curr) : childB(curr);
            } else if (childA(curr) < numCount){
                swapChild = childA(curr);
            } else if (childB(curr) < numCount){
                swapChild = childB(curr);
            } else {
                break;
            }
            if (nums[swapChild] > nums[curr]) {
                swap(nums[swapChild], nums[curr]);
                curr = swapChild;
            } else {
                break;
            }
        }
    }
    numCount = temp;
    temp = -1;
    int i, newCount = 0;
    for (i = 0; i < numCount; i++) {
        if (temp != nums[i]) {
            nums[newCount++] = nums[i];
            temp = nums[i];
        }
    }
    numCount = newCount;
}

int test(int threshold){
    int temp;
    if (threshold == -1) {
        temp = nums[threshold];
    }
    int i = -1;
    while (expr[++i] <= nums[threshold] && i < expLen) {
    }
    if (i >= expLen) {
        return 1 == 1;
    }
    sti = 1;
    stack[0] = expr[i++];
    for (; i < expLen; i++) {
        if (expr[i] <= nums[threshold]) {
            continue;
        }
        if (stack[sti-1] == expr[i] && sti) {
            sti--;
        } else {
            stack[sti++] = expr[i];
        }
    }
    if (threshold == -1) {
        nums[threshold] = temp;
    }
    return sti == 0;
}

int main (int argc, const char * argv[])
{
    scanf("%d", &expLen);
    
    int i;
    
    for (i = 0; i < expLen; i++) {
        scanf("%d", &expr[i]);
        push(expr[i]);
    }
    
    sort();
    
    if (test(-1)) {
        printf("0\n");
        return 0;
    }
    
    int start = 0, end = numCount - 1;
    int min = nums[end];
    
    while (start <= end) {
        int mid = (start + end) / 2;
        if (test(mid)) {
            if (nums[mid] < min) {
                min = nums[mid];
            }
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}

