#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int f(int z){
	if (z == 0) return 0;
	char tmp[15];
	sprintf(tmp, "%d", z);
	sort(tmp, tmp + strlen(tmp));
	int y;
	sscanf(tmp, "%d", &y);
	return f(z - y) + 1;
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d\n", f(x));
}
