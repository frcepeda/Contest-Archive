#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int H, M;

int main() {
	while (scanf(" %d:%d ", &H, &M), (H || M)){
		double ht = (H + M / 60.0) * 360.0 / 12.0;
		double mt = M * 360.0 / 60.0;
		double t = fabs(mt - ht);
		printf("%.3lf\n", min(t, 360 - t));
	}
}