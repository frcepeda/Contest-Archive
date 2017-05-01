#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class CoinConstruction {
public:
	vector<int> construct(int k){
		vector<int> v;

		k++;

		int N;

		for (N = 0; (1<<(N+1)) <= k; N++)
			v.push_back(1<<N);

		int rem = k - (1<<N);

		if (rem > 0)
			v.push_back(rem);

		return v;
	}
};

#ifdef LOCAL
int main(){
	CoinConstruction c;
	printf("%u\n", c.construct(1000000).size());
	printf("%u\n", c.construct(999999).size());
}
#endif
