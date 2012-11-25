#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

int min(int a, int b){
	return a < b ? a : b;
}

int best;

#define swap(a,b) tmp = a; a = b; b = tmp

#define len(n) ((1U<<(n)) - 1)

int doStuff(int a, int b, int c, int d, int n){
	best = max(best, a <= d && c <= b ? min(b,d) - max(a,c) + 1 : 0);

	if (n > 1){
		if (a == b && a == len(n-1) + 1) return;
		if (c == d && c == len(n-1) + 1) return;

		if (a <= len(n-1) && b > len(n-1)){
			if (len(n-1) - a + 1 > b - len(n-1) - 1){
				b = len(n-1);
			} else {
				a = 1;
				b = (b-1) - len(n-1);
			}
		} else {
			a = a <= len(n-1) ? a : (a-1) - len(n-1);
			a = max(1,a);
			b = b <= len(n-1) ? b : (b-1) - len(n-1);
			b = max(1,b);
		}

		if (c <= len(n-1) && d > len(n-1)){
			if (len(n-1) - c + 1 > d - len(n-1) - 1){
				d = len(n-1);
			} else {
				c = 1;
				d = (d-1) - len(n-1);
			}
		} else {
			c = c <= len(n-1) ? c : (c-1) - len(n-1);
			c = max(1,c);
			d = d <= len(n-1) ? d : (d-1) - len(n-1);
			d = max(1,d);
		}

		doStuff(a,b,c,d,n-1);
	}
}

int main(void){
	int a, b, c, d;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	doStuff(a,b,c,d,31);

	printf("%d\n", best);

	return 0;
}
