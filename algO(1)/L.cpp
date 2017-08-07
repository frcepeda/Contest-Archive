#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 100100;

int T, N, p[maxn], fail[maxn];
char a[maxn];

int main(){
	cin >> T;

	while (T--){
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> p[i];

		a[0] = 'a';
		for (int i = 1; i < N; i++)
			a[i] = p[i] ? a[p[i]-1] : 'b';
		a[N] = '\0';

		fail[0] = fail[1] = 0;

		for (int i = 2; i <= N; i++){
			fail[i] = fail[i-1];
			while (fail[i] && a[fail[i]] != a[i-1])
				fail[i] = fail[fail[i]];
			if (a[fail[i]] == a[i-1])
				fail[i]++;
		}

		bool works = equal(p, p+N, fail+1);

		if (works)
			cout << a << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
}
