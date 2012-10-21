//
//  main.c
//  Palin
//
//  Created by Freddy Roman Cepeda on 1/11/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <stdio.h>
#define Min(a,b) (a<b?a:b)

char cadena[5002];
int n = 1;
int DP[2][5005];

int main (int argc, const char * argv[])
{
    int ap1, ap2;
    //int *curr = DP[0];
    //int *curr2 = DP[1];
    scanf("%s",cadena+1);
    while(cadena[n] != '\0' && cadena[n] != '\n' && cadena[n] != '\r') n++;
    for(ap1 = n; ap1 > 0; ap1--){
        for(ap2 = ap1+1; ap2 <= n; ap2++){
            if(cadena[ap1]==cadena[ap2])
                DP[ap1%2][ap2]=DP[(ap1+1)%2][ap2-1];
            else
                DP[ap1%2][ap2]=Min(DP[(ap1+1)%2][ap2],DP[ap1%2][ap2-1])+1;
        }
        /*
        for(ap2=ap1+1;ap2<=n;ap2++){
            if(cadena[ap1]==cadena[ap2])
                curr[ap2]=curr2[ap2-1];
            else
                curr[ap2]=Min(curr2[ap2],curr[ap2-1])+1;
        }
        int *T = curr;
        curr = curr2;
        curr2 = T;
         */
    }
    printf("%d\n",DP[1][n-1]);
    return 0;
}