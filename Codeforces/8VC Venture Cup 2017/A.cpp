#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;

bool prime(int x){
	if (x <= 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;

	for (int i = 3; i*i <= x; i += 2)
		if (x % i == 0)
			return false;

	return true;
}

int main(){
	scanf("%d", &n);

	int i;
	for (i = 1;; i++)
		if (!prime(n*i+1))
			break;

	printf("%d\n", i);
}
