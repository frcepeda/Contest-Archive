#include <stdio.h>

int gcd(int a, int b){
	int t;

	while (b != 0){
		t = b;
		b = a%t;
		a = t;
	}
	
	return a;
}

int main(){
	int a,b;

	while (scanf("%d %d", &a, &b) != EOF)
		printf("%d\n", gcd(a,b));

	return 0;
}
