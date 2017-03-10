#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	int N;
	
	while (scanf("%d %*d", &N) != EOF){
		int x = 0, y;
		while (N--){
			scanf("%d", &y);
			x ^= y;
		}
		printf("%s\n", x ? "Vida" : "Andrea");
	}
}
