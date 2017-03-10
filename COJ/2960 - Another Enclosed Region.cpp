#include <cstdio>
#include <cstring>

using namespace std;

int f[] = {1,2,0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0};

int main(){
	char tmp[1010];
	scanf("%s", tmp);
	int ans = 0, len = strlen(tmp);
	for (int i = 0; i < len; i++)
		ans += f[tmp[i]-'A'];
	printf("%d\n", ans);
}
