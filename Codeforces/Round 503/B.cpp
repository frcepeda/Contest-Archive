#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int opp(int x){
	if (x <= n/2) return x + n/2;
	return x - n/2;
}

int q(int x){
	int ans;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &ans);
	return ans;
}

int main(){
	scanf("%d", &n);

	if (n/2 % 2 == 1){
		printf("! -1\n");
		return 0;
	}

	int lo = 1, hi = 1 + n/2, mid;
	long long midv;
	long long lov = q(hi) - q(lo);
	long long hiv = -lov;

	while (hi - lo > 1){
		mid = (lo + hi)/2;
		midv = q(opp(mid)) - q(mid);

		if (lov * midv <= 0){
			hi = mid;
			hiv = midv;
		} else {
			lo = mid;
			lov = midv;
		}
	}

	printf("! %d\n", q(hi) == q(opp(hi)) ? hi : lo);
}
