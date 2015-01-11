#include <cstdio>

using namespace std;

#define MAXS 100100

int S, B;
int left[MAXS], right[MAXS];

int main(){
	while (scanf("%d %d", &S, &B), (S || B)){
		for (int i = 0; i <= S; i++){
			left[i] = i-1;
			right[i] = i+1;
		}
		right[S] = 0;
		left[0] = 0;

		while (B--){
			int l, r;

			scanf("%d %d", &l, &r);

			left[right[r]] = left[l];
			right[left[l]] = right[r];

			if (left[l])
				printf("%d ", left[l]);
			else
				printf("* ");

			if (right[r])
				printf("%d\n", right[r]);
			else
				printf("*\n");
		}

		printf("-\n");
	}
}
