#include <cstdio>
#include <algorithm>

using namespace std;

int k, d;

int main(){
	int i;

	scanf("%d %d", &k, &d);

	if (d != 0){
		printf("%d", d);
		for (i = 1; i < k; i++)
			putchar('0');
	} else {
		if (k == 1)
			putchar('0');
		else
			printf("No solution");
	}

	putchar('\n');
}
