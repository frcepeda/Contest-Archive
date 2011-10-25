#include <stdio.h>
#include <stdlib.h>

#define isEven(num) (num % 2 == 0)

int main()
{
    long long int height, width, answer;
    scanf("%lld %lld", &height, &width);

    if(height == width){
        answer = height;
    } else if(isEven(height) && isEven(width)){
        answer = (height * width) / 2;
    } else {
        answer = height * width;
    }
    printf("%lld\n", answer);
    return 0;
}
