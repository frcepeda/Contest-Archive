#include <cstdio>
#include <set>
#include <algorithm>
#include <climits>
#include <vector>
#include <iterator>

using namespace std;

typedef long long ll;

const int maxn = 370000;
const ll MOD = 1000000007LL;
int n;
bool t[maxn];
int p[maxn];
vector<int> acs;

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		char tmp[10];
		scanf("%s %d", tmp, &p[i]);
		t[i] = tmp[1] == 'C';
		if (t[i]){
			acs.push_back(i);
		}
	}

	ll ans = 1;

	set<int> curr;

	int last = 1;
	int L = INT_MIN, R = INT_MAX;
	for (int i = 0; i < acs.size(); i++){
		if (p[acs[i]] < L || p[acs[i]] > R){
			printf("0\n");
			return 0;
		}

		ans = (ans * 2) % MOD;

		for (; last < acs[i]; last++){
			if (t[last])
				curr.erase(p[last]);
			else
				curr.insert(p[last]);
		}

		const auto old = curr.find(p[acs[i]]);
		L = old == curr.begin() ? INT_MIN : *prev(old);
		R = old == curr.end() || next(old) == curr.end() ? INT_MAX : *next(old);

		curr.erase(p[acs[i]]);
		last++;
	}

	int cnt = 1;
	for (; last <= n; last++)
		if (L <= p[last] && p[last] <= R)
			cnt++;

	printf("%d\n", (int)(ans * cnt % MOD));
}
