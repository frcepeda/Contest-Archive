#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100000

typedef struct {
    int a, b;
} Pair;

void clear(void);
int test(int,int,int);

int num;

Pair unvisited;
Pair repeated;

int start;

int next[MAXSIZE];
int prev[MAXSIZE];
int visited[MAXSIZE];

void clear(){
    int i;
    for(i = 0; i < MAXSIZE; i++)
        visited[i] = 0;
}

int test(int start, int change, int val){
    int temp = next[change];
    next[change] = val;
    
    int count = 0;
    
    while (start != 0 && visited[start] != 1) {
        count++;
        visited[start] = 1;
        start = next[start];
    }
    
    next[change] = temp;
    return count == num;
}

int main (int argc, const char * argv[])
{
    scanf("%d", &num);
    int i;
    
    for (i = 0; i <= num; i++) {
        prev[i] = -1;
    }
    
    for (i = 1; i <= num; i++) {
        long long int buf;
        scanf("%lld", &buf);
        if(buf < 0 || buf > num){
            buf = i;
        }
        next[i] = (int)buf;
        if (prev[next[i]] == -1) {
            prev[next[i]] = i;
        } else {
            repeated.a = prev[next[i]] < i ? prev[next[i]] : i;
            repeated.b = prev[next[i]] < i ? i : prev[next[i]];
        }
    }
    
    for (i = 0; i <= num; i++) {
        if (prev[i] == -1) {
            if (unvisited.a == 0) {
                unvisited.a = i;
            } else {
                unvisited.b = i;
                break;
            }
        }
    }
    
    int pos = 0, val = 0;
    
    if (repeated.a != 0 || repeated.b != 0) {
        if(test(unvisited.a, repeated.a, unvisited.b)){
            pos = repeated.a;
            val = unvisited.b;
        } else {
            clear();
            if(test(unvisited.b, repeated.a, unvisited.a)){
                pos = repeated.a;
                val = unvisited.a;
            } else {
                clear();
                if(test(unvisited.a, repeated.b, unvisited.b)){
                    pos = repeated.b;
                    val = unvisited.b;
                } else {
                    clear();
                    if(test(unvisited.b, repeated.b, unvisited.a)){
                        pos = repeated.b;
                        val = unvisited.a;
                    } else {
                        pos = 10/0;
                    }
                }
            }
        }
    } else {
        val = unvisited.a | unvisited.b;
        i = prev[0];
        while (i != -1) {
            visited[i] = 1;
            i = prev[i];
        }
        for (i = 1; i < num; i++) {
            if (visited[i] == 0) {
                pos = i;
                break;
            }
        }
    }
    
    if (pos == 0 && val == 0 && num == 1) {
        pos = 1;
    }
    
    printf("%d %d\n", pos, val);
    
    return 0;
}