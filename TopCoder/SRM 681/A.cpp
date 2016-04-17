#include <algorithm>
#include <climits>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

#define next(x) ((((x)^a)+b) & ((1LL<<50)-1))
#define MOD 1000000007
#define MAXV 50000

pair<long long, int> v[MAXV];
int l;

class LimitedMemorySeries2 {
public:
int getSum(int n, long long x0, long long a, long long b){
	int ans = 0;
	
	long long last = x0, curr, fol;
	v[l++] = mp(LLONG_MAX, 0);
	v[l++] = mp(x0, 0);
	for (int i = 1; i <= n; i++){
		int t;
		
		if (i < n){
		curr = next(last);
		fol = next(curr);
			t = i;
		} else {
			curr = LLONG_MAX;
		fol = next(curr);
			t = n-1;
		}

		if (last < curr && curr > fol){
			for (; curr > v[l-1].fst; l--)
				ans = (ans + min(t - v[l-1].snd, v[l-1].snd - v[l-2].snd)) % MOD;
		}

		last = curr;
	}
	
	return ans;
}
};

int main(){
	auto z = new LimitedMemorySeries2();
	z->getSum(6,2,23,1);
}
