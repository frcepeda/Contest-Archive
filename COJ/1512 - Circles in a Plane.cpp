#include <cstdio>

using namespace std;

int T;
long long N;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lld", &N);
		printf("%lld\n", N*(N-1) + 2);
	}
}
