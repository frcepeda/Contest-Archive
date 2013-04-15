#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <set>
#include <map>

using namespace std;

#define MAXN 100010

int gcd(int a, int b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

map<pair<int,bool>,int> horizontal, vertical;
set<int> horNeed, verNeed;
int hor[MAXN], ver[MAXN];
int H, W, X, Y, K;
int answer;

int findTimes(map<pair<int,bool>,int> &dir, set<int> &need, int step, int size){
	bool d = true;
	int coord = 0;
	int count = 0;

	while (count == 0 || coord != 0 || !d){
		if (need.find(coord) != need.end() && dir.find(make_pair(coord,d)) == dir.end())
			dir[make_pair(coord,d)] = count;

		if (coord + step < size && coord + step >= 0){
			coord += step;
		} else if (coord + step == size){
			coord = size-1;
			step = -step;
			d ^= true;
		} else if (coord + step == -1){
			coord = 0;
			step = -step;
			d ^= true;
		} else if (coord + step > size){
			coord = 2*size - step - coord - 1;
			step = -step;
			d ^= true;
		} else if (coord + step < -1){
			coord = -step - coord - 1;
			step = -step;
			d ^= true;
		}

		count++;
	}

	return count;
}

int main(void){
	int i, j, x, y, g;
	int xCycle, yCycle;

	scanf("%d %d %d %d %d", &W, &H, &X, &Y, &K);

	for (i = 0; i < K; i++){
		scanf("%d %d", &hor[i], &ver[i]);
		horNeed.insert(hor[i]);
		verNeed.insert(ver[i]);
	}

	xCycle = findTimes(horizontal, horNeed, X, W);
	yCycle = findTimes(vertical, verNeed, Y, H);
	
	g = gcd(xCycle, yCycle);

	for (i = 0; i < K; i++){
		bool works = false;

		for (j = 0; j < 4; j++){
			if (horizontal.find(make_pair(hor[i],j & 1)) != horizontal.end() &&
			    vertical.find(make_pair(ver[i],j >> 1)) != vertical.end() &&
			    (horizontal[make_pair(hor[i],j & 1)] - vertical[make_pair(ver[i],j >> 1)]) % g == 0){
				works = true;
				break;
			}
		}

		if (works) answer++;
	}
	
	printf("%d\n", answer);

	return 0;
}
