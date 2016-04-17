#include <iostream>
#include <algorithm>

using namespace std;

#define fst first
#define snd second

pair<int,int> a[100100];
int n, A, b[100100], c[100100], besti;
long long m, cf, cm, best, z[100100];

bool g(int y, int hi, long long rem){
	int lo = 1, mid;
	hi--;

	while (lo <= hi){
		mid = (lo+hi)/2;
		if (b[mid] <= y)
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	return y * (lo-1) - z[lo-1] <= rem;
}

long long f(int x){
	int lo, hi, mid;
	long long rem = m - (A * (n - x + 1) - (z[n] - z[x-1]));

	if (rem < 0) return -1;

	for (int i = 1; i <= n; i++)
		b[i] = a[i].fst;
	for (int i = x; i <= n; i++)
		b[i] = A;

	lo = 1; hi = A;
	while (lo <= hi){
		mid = (lo + hi)/2;
		if (g(mid, x, rem))
			lo = mid + 1;
		else
			hi = mid - 1;
	}

	for (int i = 1; i <= n && b[i] < (lo-1); i++)
		b[i] = lo-1;
	
	return cf * (n - x + 1) + cm * (lo-1);
}

int main(){
	cin >> n >> A >> cf >> cm >> m;

	for (int i = 1; i <= n; i++){
		cin >> a[i].fst;
		a[i].snd = i;
	}

	sort(a+1, a+1 + n);

	for (int i = 1; i <= n; i++)
		z[i] = z[i-1] + a[i].fst;

	for (int i = n; i > 0; i--){
		long long q = f(i);
		if (q > best){
			best = q;
			besti = i;
		}
	}

	cout << f(besti) << endl;
	for (int i = 1; i <= n; i++)
		c[a[i].snd] = b[i];
	for (int i = 1; i <= n; i++)
		cout << c[i] << (i < n ? ' ' : '\n');
}
