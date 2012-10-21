#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int rooms[101];
int queue[10000];
int list[101][101];
int qs, qe;
int end;

void push(int a){
    queue[qe++] = a;
}

int pop(){
    return queue[qs++];
}

int queueIsNotEmpty(){
    return qs < qe;
}

int main()
{
    int roomCount;
    scanf("%d", &roomCount);
    int i;
    for(i = 1; i <= roomCount; i++){
        int num;
        scanf("%d", &num);
        int i2;
        for(i2 = 0; i2 < num; i2++){
            scanf("%d", &list[i][i2]);
        }
        list[i][i2] = 0;
    }
    int s;
    scanf("%d %d", &s, &end);
    rooms[s] = 1;
    push(s);
    while(queueIsNotEmpty()){
        int room = pop();
        if(room == end){
            break;
        }
        int succ = rooms[room] + 1;
        i = 0;
        while(list[room][i] != 0){
            int next = list[room][i++];
            if(rooms[next] > succ || rooms[next] == 0){
                rooms[next] = succ;
                push(next);
            }
        }
    }
    printf("%d\n", rooms[end]);
    return 0;
}
