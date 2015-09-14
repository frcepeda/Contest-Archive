#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;
long long N, B, B_;

ll even(ll lo, ll hi){
	ll mid;

	while (lo < hi){
		mid = lo + (hi - lo)/2;
		if (mid * mid < B_)
			lo = mid + 1;
		else
			hi = mid;
	}
	lo--;

	return lo - (lo % 2);
}

ll odd(ll lo, ll hi){
	ll mid;

	while (lo < hi){
		mid = lo + (hi - lo)/2;
		if (mid * mid <= B_)
			lo = mid + 1;
		else
			hi = mid;
	}
	lo--;

	return lo - (1 - (lo % 2));
}

int main(){
	while (scanf("%lld %lld", &N, &B) == 2){
		long long R, C;
		B_ = N*N - B + 1;
		ll K;

		if (N % 2 == 0){
			K = even(0, sqrt(B_) + 100);
			R = N/2+1 - K/2;
			C = N/2 - K/2;

			B_ -= K*K + 1;
		} else {
			K = odd(0, sqrt(B_) + 100);
			R = N/2+1 - K/2;
			C = N/2 - K/2 + 1;

			B_ -= K*K;

			if (B_ > 0){
				B_ -= 1;
				C -= 1;
			}
		}

		//printf("K = %lld *** ", K);

		if (B_ >= K){
			R += K;
			B_ -= K;

			if (B_ >= K+1){
				C += K + 1;
				B_ -= K + 1;

				if (B_ >= K+1){
					R -= K + 1;
					B_ -= K + 1;

					if (B_ >= K+1){
						C -= K + 1;
						B_ -= K + 1;
					} else {
						C -= B_;
						B_ -= B_;
					}
				} else {
					R -= B_;
					B_ -= B_;
				}
			} else {
				C += B_;
				B_ -= B_;
			}
		} else {
			R += B_;
			B_ -= B_;
		}

		printf("%lld %lld\n", R, C);
	}
}
