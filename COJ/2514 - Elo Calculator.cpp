#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n;
string ln;
double ra, w, we, k;

int main(){
	cin >> ln >> n;
	cout << "Tournament: " << ln << endl;
	cout << "Number of players: " << n << endl;
	cout << "New ratings:" << endl;

	double sum = 0;
	for (int i = 0; i < n; i++){
		cin >> ln >> ra >> w >> we >> k;
		sum += ra;
		double z = ra + k * (w - we);
		cout << fixed << setprecision(0) << ln << ' ' << z << endl;
	}

	cout << "Media Elo: " << sum / n << endl;
}
