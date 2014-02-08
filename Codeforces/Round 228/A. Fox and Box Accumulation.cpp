#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 110

priority_queue<int, vector<int>, greater<int> > q;
int n, x[MAXN];

int main(){
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
		scanf("%d", &x[i]);

	sort(x, x+n);

	for (i = 0; i < n; i++){
		if (!q.empty() && q.top() <= x[i]){
			x[i] = q.top() + 1;
			q.pop();
			q.push(x[i]);
		} else q.push(1);
	}

	printf("%d\n", q.size());
}
