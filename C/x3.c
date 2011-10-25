#include <stdio.h>

unsigned int people[1000000];

int main(void){
    int num;
    int total = 0;
    int i, j;

    scanf("%d", &num);

    for(i = 0; i < num; i++){
        scanf("%ud", &people[i]);
    }

    for(i = 0; i < num; i++){
        for(j = i + 1; j < num; j++){
            total += people[i] ^ people[j];
        }
    }

    printf("%d\n", total);
    return 0;
}
