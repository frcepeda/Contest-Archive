#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

struct rect {
	int x1, y1, x2, y2;
};

rect merge(const rect &a, const rect &b){
	rect c;

	c.x1 = max(a.x1, b.x1);
	c.x2 = min(a.x2, b.x2);
	c.y1 = max(a.y1, b.y1);
	c.y2 = min(a.y2, b.y2);

	return c;
}

const int maxn = 135000;
int n;
rect rects[maxn], L[maxn], R[maxn];

int main(){
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d %d %d %d", &rects[i].x1, &rects[i].y1, &rects[i].x2, &rects[i].y2);

	L[0].x1 = L[0].y1 = INT_MIN;
	L[0].x2 = L[0].y2 = INT_MAX;
	R[n+1] = L[0];

	for (int i = 1; i <= n; i++)
		L[i] = merge(L[i-1], rects[i]);
	for (int i = n; i > 0; i--)
		R[i] = merge(R[i+1], rects[i]);

	for (int i = 1; i <= n; i++){
		rect c = merge(L[i-1], R[i+1]);
		if (c.x1 <= c.x2 && c.y1 <= c.y2){
			printf("%d %d\n", c.x1, c.y1);
			return 0;
		}
	}
}
