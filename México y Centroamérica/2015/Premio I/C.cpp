#include <cstdio>

using namespace std;

long long N;

int main(){
	while (scanf("%lld", &N) != EOF){
		long long ans = 0, i;

		for (i = 2; i*i <= 2*N; i++)
			if (2*N % i == 0 && (i + 2*N/i) % 2 == 1)
				ans++;

		printf("%lld\n", ans);
	}
}
