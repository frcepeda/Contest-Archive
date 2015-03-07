/*
German Collegiate Programming Contest 2014: JuQueen

This one took way longer to implement than I'd like to admit it did.
It's a textbook segment tree with lazy propagation.

In the code below, v[node] stores the updates that haven't been
propagated below. s(n) takes a number and makes it 0 if it is negative
or n if it is greater than n.

While the problem isn't really complicated nor does it require
a great deal of creativity, it took me quite a while to implement nonetheless.

My takeaway from this horrible experience is

**Always state explicitly the invariants that will hold
at every step of the algorithm, no exceptions.**

In this case, the minimum/maximum of a node shall always be s(min_[n] + v[n]),
whenever the recursion has reached it.

After I did that the implementation wasn't that hard at all. *facepalm*
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXC 4600000

#define s(x) max(0, min(N, (x)))

int C, N, O;
char op[20];
int A, B, X;
int v[MAXC*4], min_[MAXC*4], max_[MAXC*4];

void propagate(int n, int l, int r){
	if (l != r) {
		v[2*n+1] += v[n];
		v[2*n+2] += v[n];
	}

	min_[n] = s(min_[n] + v[n]);
	max_[n] = s(max_[n] + v[n]);
	v[n] = 0;
}

int maxval(int a, int b, int n, int l, int r){
	propagate(n, l, r);
	if (r < a or l > b) return 0;
	if (a <= l and r <= b) return max_[n];
	return max(maxval(a, b, 2*n+1, l, (l+r)/2), maxval(a, b, 2*n+2, (l+r)/2+1, r));
}

int minval(int a, int b, int n, int l, int r){
	propagate(n, l, r);
	if (r < a or l > b) return N;
	if (a <= l and r <= b) return min_[n];
	return min(minval(a, b, 2*n+1, l, (l+r)/2), minval(a, b, 2*n+2, (l+r)/2+1, r));
}

void update(int a, int b, int x, int n, int l, int r){
	propagate(n, l, r);

	if (r < a or l > b) return;

	if (a <= l and r <= b) {
		v[n] = x;
		propagate(n, l, r);
		return;
	}

	update(a, b, x, 2*n+1, l, (l+r)/2);
	update(a, b, x, 2*n+2, (l+r)/2+1, r);

	min_[n] = min(min_[2*n+1], min_[2*n+2]);
	max_[n] = max(max_[2*n+1], max_[2*n+2]);
}

int groupchange(int a, int b, int x){
	int m = minval(a, b, 0, 0, C-1);
	int M = maxval(a, b, 0, 0, C-1);
	if (M + x > N)
		x = N - M;
	if (m + x < 0)
		x = -m;
	update(a, b, x, 0, 0, C-1);
	return x;
}

int main(){
	scanf("%d %d %d", &C, &N, &O);

	while (O--){
		scanf("%s", op);
		if (strcmp(op, "state") == 0) {
			scanf("%d", &X);
			printf("%d\n", maxval(X, X, 0, 0, C-1));
		} else if (strcmp(op, "groupchange") == 0) {
			scanf("%d %d %d", &A, &B, &X);
			printf("%d\n", groupchange(A,B,X));
		} else {
			scanf("%d %d", &A, &X);
			printf("%d\n", groupchange(A,A,X));
		}
	}
}
