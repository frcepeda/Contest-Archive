#include <cstdio>
#include <cctype>
#include <algorithm>

using namespace std;
int ans, cnt = -1;

int main(){
	char c = -1, l = '\0';

	while (isalpha(c = getchar())){
		if (l == c){
			cnt++;
		} else {
			if (cnt % 2 == 0)
				ans++;
			cnt = 1;
			l = c;
		}
	}

	if (cnt % 2 == 0)
		ans++;

	printf("%d\n", ans);
}
