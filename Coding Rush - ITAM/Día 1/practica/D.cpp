#include <stdio.h>

int main(){
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	if (a == b)
		printf("iguales\n");
	else if (a < b)
		printf("menor\n");
	else
		printf("mayor\n");
	return 0;
}
