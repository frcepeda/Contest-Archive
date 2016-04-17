#include <iostream>
#include <iomanip>
#include <algorithm>

#define MAXN 2010
#define MAXD 30100
#define OFF 15050

using namespace std;

typedef long double ld;

int n, c;
int a[MAXN];
int d[MAXD];
ld dp[MAXD][3];
bool v[MAXD][3];

ld f(int delta, int round){
	if (delta + OFF < 0 || delta + OFF >= MAXD)
		return 0;

	if (round == 3)
		return delta > 0;

	if (v[delta+OFF][round])
		return dp[delta+OFF][round];
	v[delta+OFF][round] = true;

	for (int i = 0; i < MAXD; i++){
		if (d[i] && ((round < 2 && (i-OFF) < 0) ||
			     (round == 2 && (i-OFF) > 0)))
			dp[delta+OFF][round] +=
			    d[i] / ld(c) * f(delta+i-OFF,round+1);
	}

	return dp[delta+OFF][round];
}

int main(){
	cin >> n;

	c = n * (n-1) / 2;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++){
			d[a[i]-a[j]+OFF]++;
			d[a[j]-a[i]+OFF]++;
		}
	
	cout << setprecision(10) << f(0,0) << endl;
}
