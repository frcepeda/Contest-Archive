#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

#define MAXN 120

int n, m;
int mine[MAXN];
int hisDef[MAXN], hisAtk[MAXN];
int atkCount, defCount;
int A, B;

multiset<int> remaining;

int main(){
	int i, j;
	char str[10];

	scanf("%d %d", &m, &n);

	for (i = 0; i < m; i++){
		int d;
		scanf("%s %d", str, &d);
		if (str[0] == 'D')
			hisDef[defCount++] = d;
		else
			hisAtk[atkCount++] = d;
	}

	for (i = 0; i < n; i++)
		scanf("%d", &mine[i]);

	sort(mine, mine + n);
	sort(hisAtk, hisAtk + atkCount);

	i = n-1;
	j = 0;

	while (i >= 0 && j < atkCount){
		if (mine[i] >= hisAtk[j]){
			A += mine[i] - hisAtk[j];
			i--, j++;
		} else i--;
	}

	for (i = 0; i < n; i++)
		remaining.insert(mine[i]);

	for (i = defCount-1; i >= 0; i--){
		set<int>::iterator it = remaining.upper_bound(hisDef[i]);
		if (it == remaining.end())
			break;
		remaining.erase(it);
	}

	if (i < 0){
		set<int>::reverse_iterator it = remaining.rbegin();
		for (i = atkCount-1; i >= 0; i--){
			if (it == remaining.rend() || *it < hisAtk[i])
				break;
			B += *it - hisAtk[i];
			it++;
		}

		while (i < 0 && it != remaining.rend()){
			B += *it;
			it++;
		}
	}

	printf("%d\n", max(A, B));
}
