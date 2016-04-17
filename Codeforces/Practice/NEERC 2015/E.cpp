#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;
char s[1010];

int main(){
	int i, n;

#ifdef ONLINE_JUDGE
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
#endif

	scanf("%s", s);

	n = strlen(s);
	
	for (i = 0; i < n; i++){
		putchar(s[i]);
		if (s[i] == '-'){
			putchar(s[i+1]);

			for (i += 2; s[i] == '0'; i++)
				printf("+0");

			if (isdigit(s[i])){
				putchar('+');
				for (; isdigit(s[i]); i++)
					putchar(s[i]);
			}

			i--;
		}
	}

	putchar('\n');
}
