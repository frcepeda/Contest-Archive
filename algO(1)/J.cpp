#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;

int T, N, a[maxn] = {0, 5, 3, 2, 7, 1, 4, 6};

int main(){
	cin >> T;

	while (T--){
		cin >> N;

		if (N <= 5 || !(N & (N-1))){
			cout << "NO" << endl;
			continue;
		}

		cout << "YES" << endl;

		if (N == 6){
			cout << "5 3 2 6 1 4" << endl;
			continue;
		}

		if (N >= 8){
			for (int i = 8; i <= N; i++)
				a[i] = i;

			int b;
			for (b = 0; (1<<b) <= N; b++);
			b--;

			int l = N;
			for (int i = N; i >= 8; i--){
				if ((i-1) & (1<<b)) continue;

				for (int k = i; k < l; k++)
					a[k] = k+1;
				a[l] = i;

				l = i-1;
				b--;
			}
		}

		for (int i = 1; i <= N; i++)
			cout << a[i] << (i < N ? ' ' : '\n');

		bool works = true;
		for (int i = 1; i <= N; i++){
			works &= (i != a[i]) && !!(i & a[i]);
			if (i == a[i]) cerr << "collision: " << i << endl;
		}

		cerr << (works ? "yay!" : "welp") << endl;
	}
}
