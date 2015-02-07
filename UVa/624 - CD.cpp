#include <cstdio>
#include <algorithm>

using namespace std;

int N, M;
vector<int> l, soFar, best;
int besta;

void search(int i, int a, int c){
	if (c > 20 || a > N) return;
	
	if (N - a < besta){
		best = soFar;
		besta = N - a;
	}
	
	if (i < M){
		search(i+1, a, c);
		soFar.push_back(l[i]);
		search(i+1, a + l[i], c+1);
		soFar.pop_back();
	}
}

int main() {
	while (scanf("%d", &N) != EOF){
		l.clear();
		soFar.clear();
		besta = 1<<30;
		
		scanf("%d", &M);
		
		for (int i = 0; i < M; i++){
			int x;
			scanf("%d", &x);
			l.push_back(x);
		}
		
		search(0, 0, 0);
		
		for (int i = 0; i < best.size(); i++)
			printf("%d ", best[i]);
		printf("sum:%d\n", N - besta);
	}
}