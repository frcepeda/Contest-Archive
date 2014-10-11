#include <iostream>
#include <string>

using namespace std;

#define MOD 1000000007

typedef struct {
	long long m00, m01, m10, m11;
} mat;

mat matMult(mat a, mat b){
	mat m = {
		.m00 = (a.m00 * b.m00 + a.m01 * b.m10) % MOD,
		.m01 = (a.m00 * b.m01 + a.m01 * b.m11) % MOD,
		.m10 = (a.m10 * b.m00 + a.m11 * b.m10) % MOD,
		.m11 = (a.m10 * b.m01 + a.m11 * b.m11) % MOD,
	};
	return m;
}

mat matExp(mat a, int p){
	mat ans = {.m00 = 1, .m01 = 0, .m10 = 0, .m11 = 1};
	mat base = a;

	for (; p; p >>= 1){
		if (p % 2 == 1)
			ans = matMult(ans, base);
		base = matMult(base, base);
	}

	return ans;
}

int N, k;
long long ans;

string start, target;

int main(){
	int i;

	cin >> start;
	cin >> target;
	cin >> k;

	N = start.length();
	start = start + start;

	mat transform = {.m00 = 0, .m01 = N-1, .m10 = 1, .m11 = N-2};
	transform = matExp(transform, k);

	long long x = transform.m00;
	long long y = transform.m10;

	if (!start.compare(0, N, target))
		ans = x;

	for (i = 1; i < N; i++)
		if (!start.compare(i, N, target))
			ans = (ans + y) % MOD;

	cout << ans << endl;
}
