#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int T, P, X, Y;

typedef long double ld;

int main(){
	scanf("%d", &T);

	const ld two_pi = 2 * acos(-1);

	for (int t = 1; t <= T; t++){
		scanf("%d %d %d", &P, &X, &Y);

		Y -= 50; X -= 50;

		ld soFar = two_pi * P / 100;
		ld queryAngle = two_pi - atan2((ld)-X, (ld)Y);

		if (queryAngle < 0)
			queryAngle += two_pi;
		else if (queryAngle >= two_pi)
			queryAngle -= two_pi;

		bool on = X*X + Y*Y <= 50*50 && queryAngle <= soFar;

		printf("Case #%d: %s\n", t, on ? "black" : "white");
	}
}
