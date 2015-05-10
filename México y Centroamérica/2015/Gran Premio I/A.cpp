#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

#define MAXN 10010
#define MAXE MAXN

using namespace std;

struct out {
	int u, v, w;
};

bool operator < (const out &a, const out &b){
	return a.w > b.w;
}

priority_queue<out, std::vector<out> > q;

void push(int a, int b, int c){
	out o = {a, b, c};
	q.push(o);
}

int T, N, M, R;
bool v[MAXN];

int p[MAXN];

int id(int a){
	if (p[a] == a)
		return a;
	return p[a] = id(p[a]);
}

void join(int a, int b){
	p[id(a)] = id(b);
}

vector<out> output;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%d %d %d", &N, &M, &R);

		for (int i = 0; i < N; i++)
			p[i] = i;

		output.clear();
		fill(v, v + N, false);

		while (M--){
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			push(a, b, c);
		}

		v[R] = true;

		int ans = 0, X = N;

		while (!q.empty()){
			out o = q.top(); q.pop();

			if (v[o.v] || id(o.u) == id(o.v)) continue;
			X--;
			v[o.v] = true;
			output.push_back(o);
			ans += o.w;
			join(o.u, o.v);
		}

		if (X != 1)
			printf("impossible\n");
		else {
			printf("%d\n", ans);
			for (int i = 0; i < output.size(); i++)
				printf("%d %d %d\n", output[i].u, output[i].v, output[i].w);
		}
	}
}
