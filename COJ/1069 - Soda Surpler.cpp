#include <cstdio>

using namespace std;

int N, E, F, C;

int main(){
	scanf("%d", &N);

	while (N--){
		int curr, drank = 0;
		scanf("%d %d %d", &E, &F, &C);

		curr = E + F;
		drank = 0;

		if (C > 1){
			while (curr >= C){
				drank++;
				curr -= C;
				curr++;
			}
		}

		printf("%d\n", drank);
	}
}
