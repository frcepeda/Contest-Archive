#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int turns;
    int num;
} Step;

Step queue[4000000];
int qs, qe;

#define queueIsNotEmpty (qs<qe)

void push(Step);
void push(Step i){
    queue[qe++] = i;
}

Step pop(void);
Step pop(void){
    return queue[qs++];
}

int visited[1000000];
int end;

int main (int argc, const char * argv[])
{
    Step start;
    start.turns = 0;
    scanf("%d", &start.num);
    scanf("%d", &end);
    int count;
    scanf("%d", &count);
    while (count--) {
        int num;
        scanf("%d", &num);
        visited[num] = 1;
    }
    push(start);
    if (visited[start.num]) {
        pop();
    }
    while (queueIsNotEmpty) {
        Step curr = pop();
        visited[curr.num] = 1;
        if (curr.num == end) {
            printf("%d\n", curr.turns);
            exit(0);
        }
        Step next;
        next.turns = curr.turns + 1;
        int i;
        for (i = 0; i < 6; i++) {
            next.num = curr.num;
            int digit = (int)(next.num / pow(10, i)) % 10;
            if (digit == 9) {
                next.num -= pow(10, i) * 9;
            } else {
                next.num += pow(10, i);
            }
            if (!visited[next.num]) {
                push(next);
                visited[next.num] = 1;
            }
            next.num = curr.num;
            if (digit == 0) {
                next.num += 9 * pow(10, i);
            } else {
                next.num -= pow(10, i);
            }
            if (!visited[next.num]) {
                push(next);
                visited[next.num] = 1;
            }
        }
    }
    printf("-1\n");
    return 0;
}

