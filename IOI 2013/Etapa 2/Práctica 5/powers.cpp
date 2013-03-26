#include <cstdio>
#include <set>
#include <cmath>

using namespace std;

set<unsigned long long int> thing;
unsigned long long int N;

unsigned long long int square(unsigned long long int n){
	return n * n;
}

int main(){
	unsigned long long int i, j, k, num;

	scanf("%llu", &N);

	for (i = 3; i <= 60; i++){
		for (j = 2;; j++){
			num = 1;

			for (k = 0; k < i && num <= N; k++)
				num *= j;

			if (num > N || k < i) break;

			if (square((unsigned long long int)sqrt((long double)num)) == num) continue;

			thing.insert(num);
		}
	}

	printf("%llu\n", (unsigned long long int)sqrt((long double)N) + thing.size());
}
