#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define mp make_pair

multiset<int> m[3];
int k, n[3], t[3];

int main(){
	int i, j;

	scanf("%d", &k);

	for (i = 0; i < 3; i++)
		scanf("%d", &n[i]);
	for (i = 0; i < 3; i++)
		scanf("%d", &t[i]);

	for (i = 0; i < 3; i++)
		for (j = 0; j < n[i]; j++)
			m[i].insert(0);

	while (k--){
		int x;
		multiset<int>::iterator it[3];

		it[0] = m[0].begin();
		it[1] = m[1].begin();
		it[2] = m[2].begin();

		x = *it[0];
		x = max(x + t[0], *it[1]);
		x = max(x + t[1], *it[2]);
		x -= t[0] + t[1];

		m[2].erase(it[2]);
		m[1].erase(it[1]);
		m[0].erase(it[0]);

		m[0].insert(x + t[0]);
		m[1].insert(x + t[0] + t[1]);
		m[2].insert(x + t[0] + t[1] + t[2]);
	}

	printf("%d\n", *m[2].rbegin());
}
