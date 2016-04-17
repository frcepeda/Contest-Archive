#include <cstdio>
#include <set>

#define L 15

using namespace std;
typedef unsigned long long ull;

int main(){
	int a, b, c, d, x, y;

	ull tw[L], th[L];
	set<ull> s;

	tw[0] = th[0] = 1;
	for (a = 1; a < L; a++){
		tw[a] = tw[a-1] * 2;
		th[a] = th[a-1] * 3;
	}
	tw[0] = th[0] = 0;

	for (x = 0; x < L; x++)
	for (y = 0; y < L; y++)
	for (c = 0; c < L; c++)
	for (d = 0; d < L; d++)
	for (a = c+1; a < L; a++)
	for (b = d+1; b < L; b++)
		s.insert(((!x) + tw[x]) * ((!y) + th[y]) * (tw[a] + th[b] + tw[c]*th[d]));
	
	int r = 2;
	int t = 100;
	for (auto z = s.begin(); z != s.end() && t--; z++){
		printf("%lld %s\n", *z, *z - 1 == r ? ":)" : "D:");
		r = *z;
	}
}
