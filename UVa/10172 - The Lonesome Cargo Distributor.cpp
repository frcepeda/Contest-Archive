#include <cstdio>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define MAXN 110

int T, N, S, Q;
queue<int> B[MAXN];
stack<int> C;
int rem, ans;

int main() {
	scanf("%d\n", &T);
	
	while (T--){
		rem = ans = 0;
		while (!C.empty()) C.pop();
		for_each(B, B+N, [](queue<int> &x){ while (!x.empty()) x.pop(); });
		
		scanf("%d %d %d", &N, &S, &Q);
		
		for (int i = 0; i < N; i++){
			int qi, s;
			scanf("%d", &qi);
			while (qi--){
				scanf("%d", &s);
				B[i].push(s-1);
				rem++;
			}
		}
		
		int curr;
		for (curr = 0; rem; curr = (curr + 1) % N){
			ans += 2;
			
			while (!C.empty()){
				if (C.top() == curr){
					C.pop();
					ans += 1;
					rem--;
				} else if (B[curr].size() < Q) {
					B[curr].push(C.top());
					C.pop();
					ans += 1;
				} else break;
			}
			
			while (C.size() < S && !B[curr].empty()){
				C.push(B[curr].front());
				B[curr].pop();
				ans += 1;
			}
		}
		
		printf("%d\n", ans - 2);
	}
}