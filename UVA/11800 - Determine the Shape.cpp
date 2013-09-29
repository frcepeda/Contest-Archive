// Accepted
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
	int x, y;
};
typedef point vector;

bool operator < (const point &a, const point &b){
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

#define sq(a) ((a)*(a))
#define dist(p,q) (sq(p.x-q.x)+sq(p.y-q.y))

vector vec(point a, point b){
	vector p = {b.x - a.x, b.y - a.y};
	return p;
}

int dotProd(vector a, vector b){
	return a.x*b.x + a.y*b.y;
}

int crossProd(vector a, vector b){
	return a.x*b.y - a.y*b.x;
}

bool parallel(vector a, vector b){
	return crossProd(a,b) == 0;
}

point points[4];
int len[4];
bool right;

bool angleCmp(const point &a, const point &b){
	vector n = vec(points[0], a);
	vector m = vec(points[0], b);
	return atan2l(n.y, n.x) < atan2l(m.y, m.x);
}

int main(void){
	int t, T, i;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		const char *type;

		for (i = 0; i < 4; i++)
			scanf("%d %d", &points[i].x, &points[i].y);

		sort(points, points + 4);
		sort(points + 1, points + 4, angleCmp);

		for (i = 0; i < 4; i++)
			len[i] = dist(points[i], points[(i+1)%4]);

		right = dotProd(vec(points[0], points[3]),
		                vec(points[0], points[1])) == 0;

		if (len[0] == len[1] && len[1] == len[2] && len[2] == len[3]){
			if (right)
				type = "Square";
			else
				type = "Rhombus";
		} else if (len[0] == len[2] && len[1] == len[3]){
			if (right)
				type = "Rectangle";
			else
				type = "Parallelogram";
		} else if (parallel(vec(points[0], points[1]), vec(points[3], points[2]))
			|| parallel(vec(points[0], points[3]), vec(points[1], points[2])))
			type = "Trapezium";
		else
			type = "Ordinary Quadrilateral";

		printf("Case %d: %s\n", t, type);
	}

	return 0;
}
