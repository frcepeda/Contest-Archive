#include <stdio.h>

int main(void){
	int n, k, i, ans = 0;

	scanf("%d %d", &n, &k);

	while (n--){
		scanf("%d", &i);
		if (i % k == 0)
			ans++;
	}

	printf("%d\n", ans);

	return 0;
}
