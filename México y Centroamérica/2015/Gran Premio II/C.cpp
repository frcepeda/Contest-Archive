#include <cstdio>
#include <algorithm>

using namespace std;

int A, B;

int main(){
	while (scanf("%d %d", &A, &B) == 2)
		printf("%d\n", max(A, B));
}
