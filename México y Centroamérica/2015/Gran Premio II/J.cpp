#include <cstdio>
#include <algorithm>

#define MAXJ 500

using namespace std;

int J, R;
int S[MAXJ];

int main(){
	while (scanf("%d %d", &J, &R) == 2){
		fill(S, S+J, 0);

		for (int i = 0; i < R; i++)
			for (int j = 0; j < J; j++){
				int x;
				scanf("%d", &x);
				S[j] += x;
			}

		int x = *max_element(S, S + J);

		for (int i = J-1; i >= 0; i--)
			if (S[i] == x){
				printf("%d\n", i+1);
				break;
			}
	}
}
