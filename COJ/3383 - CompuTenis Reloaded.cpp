#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int N, S, J, D;
char s[100100];

int main(){
	scanf("%d %d %d %d", &N, &S, &J, &D);
	scanf("%s", s);

	int A = 0, B = 0;
	int a = 0, b = 0;
	for (int i = 0; i < N; i++){
		if (s[i] == 'A') a++;
		else b++;

		if (max(a,b) >= J && abs(a-b) >= D){
			if (a > b) A++;
			else B++;
			a = b = 0;
		}
	}

	printf("%d %d\n", A, B);
}
