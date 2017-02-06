#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

long long R, N;

typedef long double ld;

int main(){
	ld PI = 3.1415927;//atan(1) * 4;

	cout << setprecision(10);

	while (cin >> R >> N, (R || N)){
		if (N < 1e7){
			ld theta = 4*PI/N;
			ld A1 = R*R*sin(theta)/2;
			ld B = R * sqrt(2*(1 - cos(theta)));
			ld h = A1 * 2 / B;
			ld A2 = h*h * tan(theta/4);

			cout << A1*N - A2*N << endl;
		} else cout << PI*R*R << endl;
	}
}
