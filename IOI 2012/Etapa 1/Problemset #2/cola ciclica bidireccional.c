#include <stdio.h>

int queue[50];
int tempq[50];
int num, queries;

int main (int argc, const char * argv[])
{
    scanf("%d", &num);
    int i;
    for (i = 0; i < num; i++) {
        queue[i] = (i % num) + 1;
    }
    int moves = 0, completed = -1;
    scanf("%d", &queries);
    while (completed++, queries--) {
        int next;
        scanf("%d", &next);
        for (i = 0; i < num; i++) {
            if (queue[i] == next) {
                break;
            }
        }
        int left = i;
        int right = num - i;
        if (left < right) {
            moves += left;
        } else {
            moves += right;
        }
        int newCount = 0;
        int temp = i;
        for (i = (i + 1) % num; i != temp % num; i = (i+1) % num) {
            if (queue[i] != next) {
                tempq[newCount++] = queue[i];
            }
        }
        for (i = 0; i < newCount; i++) {
            queue[i] = tempq[i];
        }
        num = newCount;
    }
    printf("%d\n", moves);
    return 0;
}

