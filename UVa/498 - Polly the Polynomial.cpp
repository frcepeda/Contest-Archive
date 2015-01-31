#include <cstdio>
#include <cctype>

using namespace std;

int n;
int a[100000];

int eval(int x){
	int r = 0;
	for (int i = 0; i < n; i++)
		r = r*x + a[i];
	return r;
}

int main() {
	while (true){
		char c;
		int x, sr;
		
		if (!isdigit(c = getchar()) && c != '-') break;
		ungetc(c, stdin);
		
		n = 0;
		do scanf("%d%c", &a[n++], &c); while(c != '\n');
		
		bool first = true;
		do {
			sr = scanf("%d%c", &x, &c);
			printf("%s%d", first ? "" : " ", eval(x));
			first = false;
		} while (c == ' ' && sr == 2);
		putchar('\n');
	}
}