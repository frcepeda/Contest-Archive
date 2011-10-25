#include <stdio.h>
#include <stdlib.h>

int main(){
    int song[100000];
    int notes, questions;
    int i, j = 0;
    scanf("%d %d", &notes, &questions);
    for(i = 1; i <= notes; i++){
        int duration;
        scanf("%d", &duration);
        while(duration--){
            song[j++] = i;
        }
    }
    for(i = 0; i < questions; i++){
        int question;
        scanf("%d", &question);
        printf("%d\n", song[question]);
    }
    return 0;
}
