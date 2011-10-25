#include <stdio.h>
#include <stdlib.h>

void push(int);
int pop(void);
void reverse(int,int);

int stack[6000];
int sti;
char string[10010];

void push(int num){
    stack[sti++] = num;
}

int pop(){
    return stack[--sti];
}

void reverse(int start, int end){
    while (++start < --end) {
        char temp = string[start];
        string[start] = string[end];
        string[end] = temp;
    }
}

int main (int argc, const char * argv[])
{
    int i;
    
    gets(string);
    
    for(i = 0; string[i] != '\0'; i++){
    }
    
    const int read = i;
    
    for(i = 0; i < read; i++){
        switch (string[i]) {
            case '(':
                push(i);
                continue;
            case ')':
                reverse(pop(), i);
                continue;
            default:
                continue;
        }
    }
    
    for(i = 0; i < read; i++){
        switch (string[i]) {
            case '(':
            case ')':
                continue;
            default:
                printf("%c", string[i]);
                continue;
        }
    }
    
    printf("\n");
    
    return 0;
}

