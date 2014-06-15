// Accepted
// Written by Diego Terán
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

char p[55];
char q[55];
int T,lp,lq;

int main()
{
    int i,k,j;
    scanf("%d",&T);
    for(i=0;i<T;i++){
        scanf("%s", p);
        scanf("%s",q);
        lp = strlen(p);
        lq = strlen(q);
        for( k=0,j=0 ; p[k]==q[k] ; j++,k++);
        if((lq-j+lp-j)>(lp+1)){
            printf("*");
            printf("%s",p);
            printf("*\n");
        }
        else{
            for(k=0;k<lq-j;k++)
                printf("<");
	    for(k=j;k<lp;k++)
		printf("%c", p[k]);
            printf("*\n");
        }

    }

    return 0;
}
