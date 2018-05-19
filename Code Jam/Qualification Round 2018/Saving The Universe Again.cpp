#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int T;
ll D;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";

		int swaps = 0;
		ll curr = 0;

		int cnt[35] = {0};

		string P;

		cin >> D >> P;

		int power = 0;
		for (char c: P){
			if (c == 'S'){
				cnt[power]++;
				curr += 1LL<<power;
			} else if (c == 'C')
				power++;
		}

		while (power && curr > D){
			if (cnt[power]){
				cnt[power-1]++;
				cnt[power]--;
				curr -= 1LL<<power;
				curr += 1LL<<(power-1);
				swaps++;
			} else power--;
		}

		if (curr > D)
			cout << "IMPOSSIBLE\n";
		else
			cout << swaps << "\n";
	}
}
