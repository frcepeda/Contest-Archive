#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> g;
priority_queue<int, vector<int>, greater<int>> l;

int main() {
	int X;
	while (scanf("%d", &X) != EOF){
		l.push(X);
		
		while (g.size() < l.size()){
			g.push(l.top());
			l.pop();
		}
		
		while (l.size() < g.size()){
			l.push(g.top());
			g.pop();
		}
		
		if (g.size() < l.size())
			printf("%d\n", l.top());
		else
			printf("%lld\n", ((long long)l.top() + g.top()) / 2);
	}
}
