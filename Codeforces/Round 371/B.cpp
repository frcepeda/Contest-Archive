#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N;
int p[4][2];

int q(int x[4]){
	if (x[0] > x[2] || x[1] > x[3])
		return 0;
	cout << '?';
	for (int k = 0; k < 4; k++)
		cout << ' ' << min(max(x[k], 1), N);
	cout << endl;
	fflush(stdout);
	int ret;
	cin >> ret;
	return ret;
}

int idx, target;

bool worksPos(int z){
	int a[4] = {1, 1, N, N};
	a[idx] = z;
	return q(a) >= target;
}

bool worksNeg(int z){
	int a[4] = {1, 1, N, N};
	a[idx] = z;
	return q(a) < target;
}

int bb(int lo, int hi, int _idx, int _target, bool (*P)(int)){
	int mid;

	idx = _idx;
	target = _target;

	while (lo < hi){
		mid = (lo + hi)/2;
		if (P(mid))
			hi = mid;
		else
			lo = mid + 1;
	}
	
	return hi;
}

int down(){
	p[0][0] = bb(1, N+1, 0, 2, worksNeg) - 1;
	p[0][1] = bb(p[0][0], N+1, 0, 1, worksNeg) - 1;
}

int left(){
	p[1][0] = bb(1, N+1, 1, 2, worksNeg) - 1;
	p[1][1] = bb(p[1][0], N+1, 1, 1, worksNeg) - 1;
}


int up(){
	p[2][0] = bb(1, N, 2, 2, worksPos);
	p[2][1] = bb(1, p[2][0], 2, 1, worksPos);
}

int right(){
	p[3][0] = bb(1, N, 3, 2, worksPos);
	p[3][1] = bb(1, p[3][0], 3, 1, worksPos);
}

int main(){
	cin >> N;

	up(); down(); right(); left();

	for (int i = 0; i < (1<<4); i++){
		int a[4], b[4];
		for (int j = 0; j < 4; j++){
			if (i & (1<<j)){
				a[j] = p[j][0];
				b[j] = p[j][1];
			} else {
				a[j] = p[j][1];
				b[j] = p[j][0];
			}
		}

		if (q(a) == 1 && q(b) == 1){
			cout << '!';
			for (int k = 0; k < 4; k++)
				cout << ' ' << a[k];
			for (int k = 0; k < 4; k++)
				cout << ' ' << b[k];
			cout << endl;
			fflush(stdout);
			return 0;
		}
	}
}
