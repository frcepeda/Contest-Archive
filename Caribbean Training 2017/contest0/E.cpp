#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

void dfs(int n, int m){
	if (n < 0) return;

	if (n == 0){
		for (int i = 0; i < v.size(); i++)
			printf("%d%c", v[i], i+1 < v.size() ? '+' : '\n');
		return;
	}

	for (int i = min(n,m); i >= 1; i--){
		v.push_back(i);
		dfs(n-i, i);
		v.pop_back();
	}
}

int main(){
	int n;
	scanf("%d", &n);
	dfs(n, n);
}
