#include <iostream>
#include <set>
#include <algorithm>

#define fst first
#define snd second

using namespace std;

typedef pair<int,int> pii;

const int maxn = 110, D = 24*60;
int T, S, Ac, Aj;
pair<pii, bool> I[2*maxn];
multiset<int> diff, pay;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		diff.clear();
		pay.clear();

		cin >> Ac >> Aj;

		S = Ac + Aj;

		for (int i = 0; i < S; i++){
			cin >> I[i].fst.fst >> I[i].fst.snd;
			I[i].snd = i < Ac;
		}

		sort(I, I + S);

		int delta = 0;

		for (int i = 0; i < S; i++){
			int p = (S+i-1)%S;

			int d = (D + I[i].fst.fst - I[p].fst.snd) % D;

			if (I[i].snd){
				delta += I[i].fst.snd - I[i].fst.fst;
				d = -d;
			} else {
				delta -= I[i].fst.snd - I[i].fst.fst;
			}

			delta -= d;

			if (I[i].snd != I[p].snd) diff.insert(2*d);
			else pay.insert(2*d);
		}

		int ans = diff.size();

		while (delta != 0 && !diff.empty()){
			if (delta < 0){
				auto z = prev(diff.end());
				if (*z <= 0) break;
				delta = min(0, delta + *z);
				diff.erase(z);
			} else {
				auto z = diff.begin();
				if (*z >= 0) break;
				delta = max(0, delta + *z);
				diff.erase(z);
			}
		}

		while (delta != 0 && !pay.empty()){
			if (delta < 0){
				auto z = prev(pay.end());
				if (*z <= 0) break;
				delta = min(0, delta + *z);
				pay.erase(z);
			} else {
				auto z = pay.begin();
				if (*z >= 0) break;
				delta = max(0, delta + *z);
				pay.erase(z);
			}

			ans += 2;
		}

		cout << "Case #" << t << ": " << ans << endl;
	}
}
