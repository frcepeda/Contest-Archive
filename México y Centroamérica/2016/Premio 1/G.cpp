#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

long double xL, xR, yL, yR;

long double f(long double y){
	return y*y/12;
}

int main(){
	while (cin >> xL >> yL >> xR >> yR)
		cout << setprecision(20) << 2*(f(xL - xR) + f(yL - yR)) << endl;
}
