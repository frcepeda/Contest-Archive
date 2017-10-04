// Accepted
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

#define pb push_back

using namespace std;

typedef long long ll;

const int maxn = 100100;
int n;
ll s, a[maxn];

int simulate(vector<int> &v){
	int trips = 0;

	for (int i = 0; i < v.size(); trips++){
		if (i+1 >= v.size() || v[i] + v[i+1] > s)
			i++;
		else
			i += 2;
	}

	return trips;
}

int main(){
	scanf("%d %lld", &n, &s);

	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);

	multiset<ll> A(a, a+n), B;
	vector<int> ans;

	while (!A.empty()){
		int x = *A.begin(); A.erase(A.begin());
		auto yi = A.lower_bound(s - x + 1);

		if (yi == A.end()){
			B.insert(x);
			continue;
		}

		int y = *yi;
		A.erase(yi);

		ans.pb(x); ans.pb(y);

		if (A.empty()) continue;

		int x2 = *A.begin();

		A.erase(A.begin());

		auto y2 = A.lower_bound(s - x2 + 1);

		if (y2 != A.end()){
			A.insert(x2);
			continue;
		}

		ans.pb(x2);

		if (!B.empty()){
			ans.pb(*B.begin());
			B.erase(B.begin());
		} else if (!A.empty()){
			ans.pb(*A.begin());
			A.erase(A.begin());
		}
	}

	for (auto b: B) ans.pb(b);

	printf("%d\n", simulate(ans));
	for (int i = 0; i < ans.size(); i++)
		printf("%d%c", ans[i], i+1 < ans.size() ? ' ' : '\n');
}
