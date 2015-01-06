#include <cstdio>

/*
Notice that the problem can be restated as "Find the expected number of
inversions in a sequence of n different elements".
Define f(n) to be the answer => f(0) = f(1) = 0.
Now, for dp, take a sequence of n digits and consider the first element.
Since all the elements are different, it must be the i-th element in sorted
order, which means there are i inversions with it.
Then f(n) = f(n-1) + \sum_{i=0}^{n-1}{i/n} = n*(n-1)/4.
*/

using namespace std;

int main() {
	int t, T;
	
	scanf("%d", &T);
	
	for (t = 1; t <= T; t++){
		unsigned long long n;
		
		scanf("%llu", &n);
		
		n = n*(n-1);
		
		printf("Case %d: ", t);
		if (n % 4 == 0){
			printf("%llu\n", n/4);
		} else if (n % 2 == 0){
			printf("%llu/2\n", n/2);
		} else {
			printf("%llu/4\n", n);
		}
	}
}