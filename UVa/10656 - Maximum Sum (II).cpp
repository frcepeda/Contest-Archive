#include <cstdio>

using namespace std;

int main() {
	int N;
	
	while (scanf("%d", &N), N){
		int a, c = 0;
		
		while (N--){
			scanf("%d", &a);
			if (a)
				printf("%s%d", c++ ? " " : "", a);
		}
		
		printf("%s\n", c ? "" : "0");
	}
}