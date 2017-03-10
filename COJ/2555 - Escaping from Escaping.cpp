#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
char s[100100];
bool v[1<<19];

bool f(int x){
	fill(v, v + (1<<x), false);
	int acc = 0, i;

	for (i = 1; i < x; i++)
		acc = acc * 2 + (s[i] == '1');

	int cnt = 0;
	for (; i <= N; i++){
		acc = 2*acc - (1<<x)*(s[i-x] == '1') + (s[i] == '1');
		if (!v[acc]){
			v[acc] = true;
			cnt++;
		}
	}

	return cnt < (1<<x);
}

int main(){
	scanf("%s", s+1);
	N = strlen(s+1);

	for (int i = 0;; i++)
		if (f(i)){
			printf("%d\n", i);
			break;
		}
}
