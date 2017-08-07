#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

const int maxn = 210;

int T, N, K;
pair<int, int> c[maxn*maxn];

int score(const vector<int> &p){
	int ans = 0;

	for (int i = 0; i < K; i++)
		if (p[c[i].fst] < p[c[i].snd])
			ans++;

	return ans;
}

int main(){
	fstream test("M.in");
	fstream A("M.one");
	fstream B("M.two");

	test >> T;

	while (T--){
		test >> N >> K;

		for (int i = 0; i < K; i++)
			test >> c[i].fst >> c[i].snd;

		vector<int> left, right, p;

		for (int i = 0; i < N; i++){
			int x;
			A >> x;
			left.push_back(x);
		}

		for (int i = 0; i < N; i++){
			int x;
			B >> x;
			right.push_back(x);
		}

		if (score(left) > score(right))
			p = left;
		else
			p = right;

		cerr << "Score: " << score(p) << "/" << K << endl;

		for (int i = 0; i < N; i++)
			cout << p[i] << (i+1 < N ? ' ' : '\n');

		cerr << "Remaining: " << T << endl;
	}
}
