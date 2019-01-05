// TLE
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, q;
vector<int> a[maxn];

int main(){
	scanf("%d %d", &n, &q);

	vector<int> tmp;

	while (q--){
		int t, x, y, z;
		scanf("%d", &t);

		if (t == 1){
			scanf("%d %d", &x, &y);
			a[x].clear();
			a[x].push_back(y);
		} else if (t == 2){
			scanf("%d %d %d", &z, &y, &x);

			tmp.clear();
			tmp.reserve(a[x].size() + a[y].size());

			auto xx = a[x].begin();
			auto yy = a[y].begin();

			while (xx != a[x].end() || yy != a[y].end()){
				if (xx == a[x].end()){
					tmp.push_back(*yy);
					yy++;
				} else if (yy == a[y].end()){
					tmp.push_back(*xx);
					xx++;
				} else if (*xx < *yy){
					tmp.push_back(*xx);
					xx++;
				} else if (*xx > *yy){
					tmp.push_back(*yy);
					yy++;
				} else {
					xx++;
					yy++;
				}
			}

			swap(tmp, a[z]);
		} else if (t == 3){
			scanf("%d %d %d", &z, &y, &x);

			tmp.clear();
			tmp.reserve(a[x].size() * a[y].size());

			for (auto xx: a[x])
				for (auto yy: a[y])
					tmp.push_back(__gcd(xx,yy));

			sort(tmp.begin(), tmp.end());

			a[z].clear();

			int cnt = 0;
			for (int i = 0; i < tmp.size(); i++){
				cnt++;

				if (i+1 == tmp.size() || tmp[i] != tmp[i+1]){
					if (cnt % 2)
						a[z].push_back(tmp[i]);
					cnt = 0;
				}
			}
		} else {
			scanf("%d %d", &x, &y);

			if (binary_search(a[x].begin(), a[x].end(), y))
				putchar('1');
			else
				putchar('0');
		}
	}

	putchar('\n');
}
