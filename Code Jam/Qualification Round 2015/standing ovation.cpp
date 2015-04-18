#include <cstdio>

using namespace std;

int t, T, S;
char c[1010];

bool check(int x){
	for (int i = 0; i <= S; i++){
		if (x < i)
			return false;
		x += c[i] - '0';
	}
	return true;
}

int main(){
	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		scanf("%d %s", &S, c);

		int lo = 0, hi = 10000, mid;

		while (lo < hi){
			mid = (lo + hi) / 2;
			if (check(mid))
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("Case #%d: %d\n", t, hi);
	}
}
