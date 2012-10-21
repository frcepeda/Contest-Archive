#include <stdio.h>
#include <stdlib.h>

int tempMatrix[2000][2000];
int start[1000][8000];
int end[1000][8000];
int length[1000];

int sideLength;
int num;

int moves;

void read(int array[1000][8000]){
    int i, j;
    for(i = 0; i < sideLength; i++){
        for(j = 0; j < sideLength; j++){
            char temp;
            do{
                temp = getchar();
            } while (temp == '\n' || temp == '\r' || temp == ' ');
            tempMatrix[j][i] = (int)temp;
        }
    }

    num = (sideLength + 1) / 2;
    for(i = 0; i < num; i++){
        int a = i, b = i;
        int index = 0;
        while(a < sideLength - i){
            array[i][index++] = tempMatrix[a++][b];
        }
        a--;
        b++;
        while(b < sideLength - i){
            array[i][index++] = tempMatrix[a][b++];
        }
        b--;
        a--;
        while(a >= i){
            array[i][index++] = tempMatrix[a--][b];
        }
        a++;
        b--;
        while(b > i){
            array[i][index++] = tempMatrix[a][b--];
        }
        length[i] = index;
    }
}

void print(){
    int i;
    for(i = 0; i < num; i++){
        int j = 0;
        while(start[i][j] != 0){
            printf("%d ", start[i][j++]);
        }
        printf("\n");
    }
    printf("\n");
    for(i = 0; i < num; i++){
        int j = 0;
        while(start[i][j] != 0){
            printf("%d ", end[i][j++]);
        }
        printf("\n");
    }
}

int equals(int dial, int offset){
    int i;
    for(i = 0; i < length[dial] && i < 10; i++){
        if(end[dial][i] != start[dial][(length[dial] + i + offset) % length[dial]])
            return 0;
    }
    return 1;
}

int search(int dial){
    if(equals(dial, 0)){
        return 0;
    } else {
        int i = 0;
        int half = length[dial] / 2;
        while(i < half){
            while(start[dial][i] != end[dial][0] && i < half){
                i++;
            }
            if(equals(dial, i)){
                return abs(i);
            }
        }
        i = 0;
        while(i >= -half){
            while(start[dial][length[dial] + i] != end[dial][0] && i >= -half){
                i--;
            }
            if(equals(dial, i)){
                return abs(i);
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%i", &sideLength);

    read(start);
    read(end);

    //print();

    int i;
    for(i = 0; i < num; i++){
        moves += search(i);
    }

    printf("%i\n", moves);

    return 0;
}
