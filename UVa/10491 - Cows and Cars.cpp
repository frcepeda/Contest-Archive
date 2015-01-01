#include <cstdio>

using namespace std;

int main(){
	double cow, car, show;
	
	while (scanf("%lf %lf %lf", &cow, &car, &show) != EOF)
		printf("%.05lf\n", 
			// after choice, car + cow - show - 1 options remain
			// cow first
			cow / (car + cow) * car / (car + cow - show - 1)
			+
			// car first
			// car + cow - show - 1 options remain
			// car - 1 cars remain
			car / (car + cow) * (car - 1) / (car + cow - show - 1)
		);
}
