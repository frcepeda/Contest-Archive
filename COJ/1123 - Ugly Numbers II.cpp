#include <cstdio>
#include <queue>

using namespace std;

#define LIM 1550

typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> q;
ll p[LIM];

int main(){
	int n;
	q.push(1);

	for (int i = 0; i < LIM; i++){
		ll x = q.top(); q.pop();
		while (!q.empty() && q.top() == x)
			q.pop();
		p[i] = x;
		q.push(2*x);
		q.push(3*x);
		q.push(5*x);
	}

	while (scanf("%d", &n), n)
		printf("%lld\n", p[n-1]);
}
