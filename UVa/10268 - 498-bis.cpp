#include <cstdio>
#include <cctype>

using namespace std;

int n;
int a[100000];

int eval(int x){
	int r = 0;
	for (int i = 0; i < n-1; i++)
		r = r*x + a[i] * (n-i-1);
	return r;
}

int main() {
	int x, r;
	
	while (scanf("%d\n", &x) == 1){
		char c;
		
		n = 0;
		do r = scanf("%d%c", &a[n++], &c); while(c == ' ' && r == 2);
		
		printf("%d\n", eval(x));
	}
}