#include <stdio.h>
#include <stdlib.h>

#define summation(a) ((a)*(a+1))/2

int main(){
    int rooms;
    int queries;

    scanf("%d", &rooms);
    scanf("%d", &queries);

    while(queries--){
        char type;
        scanf("%c", &type);
        while(type != 'C' && type != 'P')
            scanf("%c", &type);
        int room, floor, answer, temp = 1;
        switch(type){
            case 'C':
                scanf("%i", &room);
                floor = 0;
                while (temp <= room){
                    temp += ++floor;
                }
                temp -= floor;
                answer = floor;
                break;
            case 'P':
                scanf("%i %i", &floor, &room);
                answer = summation(floor-1) + room;
                break;
        }
        printf("%d\n", answer);
    }

    return 0;
}
