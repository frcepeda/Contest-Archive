#include <stdio.h>
#include <math.h>

int ceiling(double num){
	int i = (int) num;
	if (num > i)
		return i + 1;
	else
		return i;
}

int main(void){
	int num;
	scanf("%d", &num);
	printf("%d\n", ceiling(log(num)/log(2)));
}

