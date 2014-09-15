#include <cstdio>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

struct plane {
	int a, b, c, d;
	double x, y, z;
};

#define MAXP 510

plane planes[MAXP];
map<string, int> ids;

int m, n;

int main() {
	int i;

	scanf("%d %d", &m, &n);

	for (i = 0; i < m; i++){
		scanf("%d %d %d %d", &planes[i].a, &planes[i].b, &planes[i].c, &planes[i].d);
		if (planes[i].c != 0){
			planes[i].z = (double)planes[i].d / planes[i].c;
		} else if (planes[i].b != 0){
			planes[i].y = (double)planes[i].d / planes[i].b;
		} else if (planes[i].a != 0){
			planes[i].x = (double)planes[i].d / planes[i].a;
		}
	}

	while (n--){
		int x, y, z;
		char tmp[MAXP];
		scanf("%d %d %d", &x, &y, &z);
		for (i = 0; i < m; i++){
			double x1 = x - planes[i].x;
			double y1 = y - planes[i].y;
			double z1 = z - planes[i].z;
			tmp[i] = ((x1 * planes[i].a + y1 * planes[i].b + z1 * planes[i].c) > 0) + 1;
		}
		ids[string(tmp)]++;
	}

	int ans = 0;
	for (map<string,int>::iterator it = ids.begin(); it != ids.end(); it++)
		ans = max(ans, it->second);

	printf("%d\n", ans);
}
