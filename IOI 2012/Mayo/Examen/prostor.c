#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 1000
#define MAXRECTS 200000

typedef struct {
	int _bit[MAXNUM][MAXNUM];
} BIT;

BIT segmentStart, segmentEnd;

void update(BIT *bit, int x, int y, int diff){
	int a,b;
	for (a = x; a < MAXNUM; a += a&-a){
		for (b = y; b < MAXNUM; b += b&-b){
			bit->_bit[a][b] += diff;
		}
	}
}

unsigned long long int query2D(BIT *bit, int x, int y){
	int a,b;
	unsigned long long int sum = 0;
	for (a = x; a > 0; a -= a&-a){
		for (b = y; b > 0; b -= b&-b){
			sum += bit->_bit[a][b];
		}
	}
	return sum;
}

unsigned long long int queryRect(BIT *b, int x1, int y1, int x2, int y2){
	return query2D(b, x2, y2) - query2D(b, x2, y1-1) - query2D(b, x1-1, y2) + query2D(b, x1-1, y1-1);
}

enum {
	start,
	rectangle,
	end
};

typedef struct {
	int type, y;
	int x1, z1;
	int x2, z2;
} event;

int eventCompare(const void *ap, const void *bp){
	event *a = (event *)ap;
	event *b = (event *)bp;
	if (a->y > b->y){
		return 1;
	} else if (b->y > a->y){
		return -1;
	} else if (a->type > b->type){
		return 1;
	} else if (b->type > a->type){
		return -1;
	} else {
		return 0;
	}
}

event makeEvent(int t, int y, int x1, int z1, int x2, int z2){
	event e = {t,y,x1,z1,x2,z2};
	return e;
}

typedef struct {
	event events[MAXRECTS];
	int count;
} sweep;

sweep XY, XZ, YZ;
int rectNum;

unsigned long long int doSweep(sweep *s){
	int i;
	unsigned long long int count = 0;

	qsort(s->events, s->count, sizeof(event), eventCompare);

	memset(&segmentStart, 0, sizeof(segmentStart));
	memset(&segmentEnd, 0, sizeof(segmentEnd));

	#define e(i) s->events[i]
	for (i = 0; i < s->count; i++){
		if (e(i).type == start || e(i).type == rectangle){
			count += queryRect(&segmentStart, e(i).x1, 1, e(i).x2, e(i).z2) -
				queryRect(&segmentEnd, e(i).x1, 1, e(i).x2, e(i).z1 - 1);
		}

		if (e(i).type == start){
			update(&segmentStart, e(i).x1, e(i).z1, 1);
			update(&segmentEnd, e(i).x2, e(i).z2, 1);
		} else if (e(i).type == end){
			update(&segmentStart, e(i).x1, e(i).z1, -1);
			update(&segmentEnd, e(i).x2, e(i).z2, -1);
		}
	}

	return count;
}

int main(void)
{
	int i, j;

	scanf("%d", &rectNum);

	for (i = 0; i < rectNum; i++){
		int x1, y1, z1, x2, y2, z2;
		scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
#define swap(a,b) int _temp = a; a = b; b = _temp
		if (x1 > x2){
			swap(x1, x2);
		}
		if (y1 > y2){
			swap(y1, y2);
		}
		if (z1 > z2){
			swap(z1, z2);
		}
		if (x1 == x2){
			XY.events[XY.count++] = makeEvent(start,	y1, x1, z1, x2, z2);
			XY.events[XY.count++] = makeEvent(end,		y2, x1, z1, x2, z2);
			XZ.events[XZ.count++] = makeEvent(rectangle,	x1, z1, y1, z2, y2);
		} else if (y1 == y2){
			YZ.events[YZ.count++] = makeEvent(start,	z1, y1, x1, y2, x2);
			YZ.events[YZ.count++] = makeEvent(end,		z2, y1, x1, y2, x2);
			XY.events[XY.count++] = makeEvent(rectangle,	y1, x1, z1, x2, z2);
		} else if (z1 == z2){
			XZ.events[XZ.count++] = makeEvent(start,	x1, z1, y1, z2, y2);
			XZ.events[XZ.count++] = makeEvent(end,		x2, z1, y1, z2, y2);
			YZ.events[YZ.count++] = makeEvent(rectangle,	z1, y1, x1, y2, x2);
		}
	}

	printf("%llu\n", doSweep(&XY) + doSweep(&XZ) + doSweep(&YZ));

	return 0;
}

