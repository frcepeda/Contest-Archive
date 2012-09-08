#include <stdio.h>

int main(void){
	double bal;
	int thing;
	
	scanf("%d %lf", &thing, &bal);
	
	if (thing % 5 == 0 && thing + .5 <= bal){
		bal -= thing + .5;
	}
	
	printf("%.2lf\n", bal);

	return 0;
}
