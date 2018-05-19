#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class LongMansionDiv1 {
public:
	long long minimalTime(vector<int> t, int sX, int sY, int eX, int eY){
		int N = t.size();
		long long ans = 1LL<<62;

		vector<long long> acc(t.size());
		acc[0] = t[0];
		for (int i = 1; i < N; i++)
			acc[i] = acc[i-1] + t[i];

		for (int i = 0; i < N; i++){
			long long curr = 0;

			curr += acc[max(sX,i)] - (min(sX,i) ? acc[min(sX,i)-1] : 0);
			curr += ((long long) abs(sY - eY) - 1) * t[i];
			curr += acc[max(eX,i)] - (min(eX,i) ? acc[min(eX,i)-1] : 0);

			ans = min(ans, curr);
		}

		return ans;
	}
};

#ifdef LOCAL
int main(){
	LongMansionDiv1 l;

	cout << l.minimalTime({5,3,10}, 2, 0, 2, 2) << endl;
}
#endif
