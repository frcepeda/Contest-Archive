// Accepted
// Place the circles in opposite corners.

#include <cstdio>
#include <algorithm>

#define sq(x) ((x)*(x))

using namespace std;
int L, C, R1, R2;

bool works(int a, int b){
	return 2*max(R1,R2) <= min(a,b) && sq(a - R1 - R2) + sq(b - R1 - R2) >= sq(R1 + R2);
}

int main() {
	while (scanf("%d %d %d %d", &L, &C, &R1, &R2), (L || C || R1 || R2))
		printf("%c\n", works(L,C) || works(C,L) ? 'S' : 'N');
}