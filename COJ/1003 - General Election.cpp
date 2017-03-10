#include <cstdio>

using namespace std;

int T, N, M;

int main(){
	scanf("%d", &T);

	while (T--){
		int v[10] = {0};
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++)
			for (int i = 0; i < N; i++){
				int z;
				scanf("%d", &z);
				v[i] += z;
			}
		int b = 0, bi;
		for (int i = 0; i < N; i++)
			if (v[i] > b){
				b = v[i];
				bi = i;
			}
		printf("%d\n", bi+1);
	}
}
