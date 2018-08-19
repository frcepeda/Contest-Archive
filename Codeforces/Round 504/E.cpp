#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int n;

bool query(int r1, int c1, int r2, int c2){
	if (r1 < 1 || r1 > n) return false;
	if (r2 < 1 || r2 > n) return false;
	if (c1 < 1 || c1 > n) return false;
	if (c2 < 1 || c2 > n) return false;
	printf("? %d %d %d %d\n", r1, c1, r2, c2);
	fflush(stdout);
	char tmp[10];
	scanf("%s", tmp);
	return tmp[0] == 'Y';
}

int main(){
	scanf("%d", &n);

	int r = 1, c = 1;

	string ans, rans;

	while (r + c - 2 < n - 1){
		if (query(r, c+1, n, n)){
			ans += 'R';
			c++;
		} else {
			ans += 'D';
			r++;
		}
	}

	r = c = n;

	while (r + c - 2 >= n){
		if (query(1, 1, r-1, c)){
			rans += 'D';
			r--;
		} else {
			rans += 'R';
			c--;
		}
	}

	reverse(rans.begin(), rans.end());
	ans += rans;

	printf("! %s\n", ans.c_str());
}
