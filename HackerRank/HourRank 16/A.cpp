#include <iostream>
#include <algorithm>

using namespace std;

int n, a[110];

int main(){
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int best = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		a[i] *= 2;

		int h = *min_element(a, a+n);

		if (h > best){
			best = h;
			cnt = 1;
		} else if (h == best){
			cnt++;
		}

		a[i] /= 2;
	}

	cout << best << ' ' << cnt << endl;
}
