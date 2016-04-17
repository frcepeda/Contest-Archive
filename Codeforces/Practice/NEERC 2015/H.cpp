#include <cstdio>
#include <algorithm>

using namespace std;

#define L 1000

int n;
char s[L];
int z[L], p[L];
int TARGET;

char *T = "bdhnptzBFHNRTZ";
//char *T = "elqsxCJMSV";
//char *T = "cfjmyAGLQUY";
//char *T = "agiouwEIOXP";
char *T = "blijpCGONRT";//"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int h(char *x){
	int r = 0;

	for (; *x != '\0'; x++)
		r = 31 * r + *x;

	return r;
}

int r = 1000;

void f(int i, int r, int a){
	if (r == 0){
		s[i] = '\0';
		if (a == TARGET){
			printf("%s\n", s);
			fflush(stdout);
			r--;
		}
		return;
	}

	for (int j = 0; T[j]; j++){
		s[i] = T[j];
		f(i+1, r-1, a*31 + T[j]);
	}
}

int main(){
	p[0] = 1;
	for (int i = 1; i < L; i++)
		p[i] = 31 * p[i-1];

	//printf("%d\n", h("edHs"));

	TARGET = h("npBF");

	for (int i = 11; r; i++)
		f(0, i, 0);
}
