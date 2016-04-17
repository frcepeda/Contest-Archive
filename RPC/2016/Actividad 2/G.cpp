#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#define sq(x) ((x)*(x))

int main(){
	long double A, B;

	while (cin >> A >> B){
		auto theta = acos((A - B)/(A + B));
		auto r = sq(A + B) * (theta - sin(2*theta)/2) - M_PI * sq(B);
		cout << fixed << setprecision(3) << r << endl;
	}
}
