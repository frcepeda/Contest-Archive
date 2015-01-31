#include <cstdio>
#include <algorithm>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

struct pt {
	int x, y, z;
};

typedef pair<pt,pt> box;
int N;
box curr;

box intersect(box a, box b){
	box c;
	c.fst.x = max(a.fst.x, b.fst.x);
	c.fst.y = max(a.fst.y, b.fst.y);
	c.fst.z = max(a.fst.z, b.fst.z);
	c.snd.x = min(a.snd.x, b.snd.x);
	c.snd.y = min(a.snd.y, b.snd.y);
	c.snd.z = min(a.snd.z, b.snd.z);
	return c;
}

int volume(box b){
	if (b.fst.x >= b.snd.x || b.fst.y >= b.snd.y || b.fst.z >= b.snd.z) return 0;
	return (b.snd.x - b.fst.x) * (b.snd.y - b.fst.y) * (b.snd.z - b.fst.z);
}

int main() {
	while (scanf("%d", &N), N--){
		int x;
		scanf("%d %d %d %d", &curr.fst.x, &curr.fst.y, &curr.fst.z, &x);
		curr.snd.x = curr.fst.x + x;
		curr.snd.y = curr.fst.y + x;
		curr.snd.z = curr.fst.z + x;
		
		while (N--){
			box b;
			scanf("%d %d %d %d", &b.fst.x, &b.fst.y, &b.fst.z, &x);
			b.snd.x = b.fst.x + x;
			b.snd.y = b.fst.y + x;
			b.snd.z = b.fst.z + x;
			curr = intersect(b, curr);
		}
		
		printf("%d\n", volume(curr));
	}
}