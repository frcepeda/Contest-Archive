#include <cstdio>
#include <algorithm>

using namespace std;

long long AB, AC, BD, num, den, g;

int main(){
	while (scanf("%I64d %I64d %I64d", &AB, &AC, &BD) != EOF){
		num = AC * AB;
		den = BD - AC;
		g = __gcd(num, den);
		printf("%I64d/%I64d\n", num/g, den/g);
	}
}
