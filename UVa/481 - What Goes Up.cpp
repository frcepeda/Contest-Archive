#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> a;

vector<int> LIS(vector<int> &x){
	vector<int> m, p(x.size());
	
	m.push_back(-1);
	for (int i = 0; i < x.size(); i++){
		int lo = 1, hi = m.size()-1, mid;
		
		while (lo <= hi){
			mid = (lo + hi) / 2;
			if (x[m[mid]] < x[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}
		
		p[i] = m[lo-1];
		if (lo >= m.size()) m.push_back(0);
		m[lo] = i;
	}
	
	vector<int> l(m.size()-1);
	for (int i = m[m.size()-1], j = m.size()-2; i != -1; j--, i = p[i])
		l[j] = x[i];
	
	return l;
}

int main() {
	int x;
	while (scanf("%d", &x) != EOF) a.push_back(x);
	
	auto v = LIS(a);
	
	printf("%d\n-\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);
}