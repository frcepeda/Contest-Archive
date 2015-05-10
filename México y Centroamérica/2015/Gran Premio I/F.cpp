#include <cstdio>
#include <cstring>

using namespace std;

char s[110];
long long N;
int T;

int main(){
	scanf("%d", &T);

	while (T--){
		scanf("%lld %s", &N, s);
		int l = strlen(s);
		for (int i = 0; i < l; i++)
			printf("%c", s[(i-N%l+l)%l]);
		putchar('\n');
	}
	
}
