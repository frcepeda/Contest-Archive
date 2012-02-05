#include <stdio.h>

int sprageGrundy(int n){
    while(n % 2)
        n /= 2;
    return n / 2;
}

int main(void){
    unsigned int n, m, a;
    scanf("%d %d", &n, &a);
    int spGrN = sprageGrundy(n);
    for(m = 1; m <= a; m++){
        if(!(spGrN ^ sprageGrundy(m)))
            printf("%d ", m);
    }
    return 0;
}
