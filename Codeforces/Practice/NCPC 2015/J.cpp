#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

#define MAXT 110
#define fst first
#define snd second

int t, n;

struct node {
	double dp[MAXT], p;
	map<string, node *> ch;
	map<string, int> ans;
	int sz;
};

node root;

void insert(node &n, vector<string> &w, int i){
	n.sz++;
	n.ans[w[w.size()-1]]++;

	if (i == w.size()-1) return;

	auto c = n.ch[w[i]];
	if (c == NULL)
		n.ch[w[i]] = c = new node();

	insert(*c, w, i+1);
}

void pre(node &n){
	for (int i = 0; i < MAXT; i++)
		n.dp[i] = -10000;

	for (auto &c: n.ch)
		pre(*c.snd);

	if (n.ch.size() == 0)
		n.p = 1;
	else {
		int m = 0;
		for (auto &z : n.ans)
			m = max(m, z.snd);
		n.p = (double) m / n.sz;
	}
}

double f(node &n, int t){
	if (t == 0) return 0;
	if (t < 0) return -100000;
	if (n.dp[t] >= 0) return n.dp[t];

	n.dp[t] = n.p + f(root, t-1);

	if (n.ch.size() > 0){
		double acc = 0;
		for (auto &w: n.ch)
			acc += f(*w.snd, t-1) * w.snd->sz / n.sz;
		n.dp[t] = max(n.dp[t], acc);
	}

	return n.dp[t];
}

int main(){
	cin >> t >> n;

	string tmp;
	getline(cin, tmp);
	while (getline(cin, tmp)){
		istringstream iss(tmp);
		vector<string> words{istream_iterator<string>(iss), istream_iterator<string>()};
		insert(root, words, 0);
	}

	pre(root);

	printf("%.8f\n", f(root, t));
}
