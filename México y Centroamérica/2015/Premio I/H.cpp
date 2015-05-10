#include <cstdio>
#include <map>

#define MAXN 1000010

using namespace std;

int N;
int A[MAXN];
map<long long,int> m;

int main(){
	int i, ans = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	long long acc = 0;
	m[0]++;

	for (int i = 0; i < N; i++){
		acc += A[i];
		map<long long,int>::iterator it = m.find(acc);
		if (it != m.end())
			ans += it->second;
		m[acc]++;
	}

	printf("%d\n", ans);
}
