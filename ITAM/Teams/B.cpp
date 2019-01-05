#include <algorithm>
#include <cstdio>

using namespace std;

int days[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main(){
	int d, m, y;
	scanf("%d/%d/%d", &d, &m, &y);
	d++;

	if (d > days[m-1]){
		d = 1;
		m++;
	}

	if (m > 12){
		m = 1;
		y++;
	}

	printf("%02d/%02d/%04d\n", d, m, y);
}
