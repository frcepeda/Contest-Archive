#include <cstdio>
#include <algorithm>
#include <utility>

using namespace std;

#define fst first
#define snd second

#define MAXN 1000010

typedef pair<int,int> pii;
pii a[MAXN];
unsigned long long int ans;
int b[MAXN], left[MAXN], right[MAXN];
int N;

int main(){
	int i, j;

	scanf("%d", &N);

	b[0] = b[N+1] = 1<<30;
	for (i = 1; i <= N; i++){
		scanf("%d", &a[i].fst);
		a[i].snd = i;
		b[i] = a[i].fst;
		left[i] = i-1;
		right[i] = i+1;
	}

	sort(a+1, a+1+N);

	for (i = 1; i < N; i++){
		int m = min(b[left[a[i].snd]], b[right[a[i].snd]]);
		ans += m;
		right[left[a[i].snd]] = right[a[i].snd];
		left[right[a[i].snd]] = left[a[i].snd];
	}

	printf("%llu\n", ans);
}
