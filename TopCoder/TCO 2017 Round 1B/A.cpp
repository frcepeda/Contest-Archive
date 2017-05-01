#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class WaterAndOxygen {
public:
	double maxDays(int remainH20, int remainO2, int costH2O, int costO2){
		double lo = 0, hi = 1e60, mid;

		for (int i = 0; i < 500; i++){
			mid = (lo + hi)/2;

			bool works = true;

			double extra = remainH20 - costH2O * mid;

			if (extra < 0)
				works = false;

			if (costO2 * mid > remainO2 + max(0.0, extra/2))
				works = false;

			if (works)
				lo = mid;
			else
				hi = mid;
		}

		return hi;
	}
};

#ifdef LOCAL
int main(){
}
#endif
