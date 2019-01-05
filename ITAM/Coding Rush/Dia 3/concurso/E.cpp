#include <stdio.h>

int health[100];
int damage[100];
int N;

bool works(int hp){
	int i, j;

	for (i = 0; i < N; i++){
		int sum = 0;
		for (j = i; j < N; j++)
			sum += damage[j];
		sum *= health[i];
		if (sum > hp)
			return false;
		hp -= sum;
	}
	return true;
}

int main(){
	int hi, lo, mid;
	int i, j;

	while (scanf("%d", &N) != EOF){
		for (i = 0; i < N; i++)
			scanf("%d", &damage[i]);
		for (i = 0; i < N; i++)
			scanf("%d", &health[i]);

		lo = 0;
		hi = 10000000;

		while (lo <= hi){
			mid = (lo+hi)/2;
			if (works(mid)){
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		printf("%d\n", lo);
	}

	return 0;
}

