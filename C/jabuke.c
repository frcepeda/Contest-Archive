#include <stdio.h>

int main(void){
    int width, boat, remaining;
    int moves = 0, pos = 1, end;
    scanf("%d %d", &boat, &width);
    scanf("%d", &remaining);
    while(remaining--){
        end = width + pos - 1;
        int nao;
        scanf("%d", &nao);
        if(nao >= pos && nao <= end)
            continue;
        if(nao < pos){
            moves += pos - nao;
            pos = nao;
        } else {
            moves += nao - end;
            pos = nao - width + 1;
        }
    }
    printf("%d", moves);
    return 0;
}
