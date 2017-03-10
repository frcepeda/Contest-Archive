#include <cstdio>

using namespace std;

int n;
int a[200];

int main(){
	while (scanf("%d", &n) != EOF){
		int s = 0;

		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			s += a[i];
		}

		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += (s - a[i]) % 2 == 0;

		printf("%d\n", ans);
	}
};
