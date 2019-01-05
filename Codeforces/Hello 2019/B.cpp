// Accepted
#include <cstdio>

using namespace std;

const int maxn = 20;
int n, a[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < (1<<n); i++){
		int acc = 0;

		for (int j = 0; j < n; j++)
			if (i & (1<<j))
				acc += a[j];
			else
				acc -= a[j];

		if (acc % 360 == 0){
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");
}
