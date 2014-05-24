// Accepted
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

set<long long> vis;

int N;

long long sortdigs(int x){
	int digs[10], l = 0;
	do {
		digs[l++] = x % 10;
		x /= 10;
	} while (x != 0);

	sort(digs, digs + l);

	long long up = 0, down = 0;

	for (int i = 0; i < l; i++){
		up *= 10;
		up += digs[i];
	}

	for (int i = l-1; i >= 0; i--){
		down *= 10;
		down += digs[i];
	}

	return down - up;
}

int f(long long x){
	if (vis.find(x) != vis.end())
		return 1;
	vis.insert(x);
	return f(sortdigs(x)) + 1;
}

int main(){
	while (scanf("%d", &N), N){
		vis.clear();
		printf("Chain length %d\n", f(N) - 1);
	}
}
