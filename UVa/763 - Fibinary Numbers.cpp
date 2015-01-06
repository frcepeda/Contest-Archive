#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXL 110

int A, B;
char a[MAXL], b[MAXL];

int main() {
	int i;
	bool first = true;
	
	while (scanf("%s %s", a, b) != EOF){
		int l = 0, c = 0;
		
		if (!first) putchar('\n');
		first = false;
		
		A = strlen(a);
		B = strlen(b);
		
		for (i = 0; i < A; i++)
			a[i] -= '0';
		for (i = 0; i < B; i++)
			b[i] -= '0';
		
		reverse(a, a + A);
		reverse(b, b + B);
			
		A = max(A,B);
		
		for (i = 0; i < A; i++)
			a[i] += b[i];
		
		for (i = A-1; i >= 0; i--){
			if (a[i] >= 2 && (!i || a[i-1] == 0)){
				a[i] -= 2;
				if (i == 0){
					a[1]++;
				} else if (i == 1){
					a[0]++;
					a[2]++;
				} else {
					a[i-2]++;
					a[i+1]++;
				}
				i += 3;
			} if (i && a[i] && a[i-1]){
				a[i+1]++;
				a[i]--;
				a[i-1]--;
				i += 3;
			}
		}
		
		for (i = 0; i < MAXL; i++)
			if (a[i])
				l = i;
		l++;
				
		for (i = 0; i < l; i++)
			a[i] += '0';
		
		reverse(a, a+l);
		puts(a);
		
		fill(a, a + MAXL, 0);
		fill(b, b + MAXL, 0);
	}
}