#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T, n;
char s[110];

bool f(int i, int j){
	if (i+1 == j) return s[i] == 'P' || s[i+1] == 'P';
	return f(i, (i+j)/2) && f((i+j)/2+1, j);
}

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%s", s);
		n = strlen(s);

		if (n == 1){
			printf("YES\n");
			continue;
		} else if (n&(n-1)){
			printf("NO\n");
			continue;
		}

		printf("%s\n", f(0, n-1) ? "YES" : "NO");
	}
}
