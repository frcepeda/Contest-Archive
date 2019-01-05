#include <stdio.h>

int main(){
	double n;

	while (scanf("%lf", &n) != EOF){
		printf("%.1lf\n", (n-32)/1.8);
	}

	return 0;
}
