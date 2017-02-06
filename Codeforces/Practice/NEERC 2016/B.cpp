#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	long long l, w, r, d, k, kd;

	scanf("%lld %lld %lld", &l, &w, &r);

	d = __gcd(w,r);

	k = (l - w + d - 1) / d;
	kd = k * d;

	if (kd == l - w) 
		kd += d;

	printf("%s\n", kd < r ? "DEADLOCK" : "OK");
}
