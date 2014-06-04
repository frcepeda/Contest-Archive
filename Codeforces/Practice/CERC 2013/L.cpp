// Accepted
#include <cstdio>

using namespace std;

int T, k;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d", &k);
		printf("%d\n", (1<<k)-1);
	}
}
