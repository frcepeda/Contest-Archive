#include <cstdio>

int main(){
	unsigned n;
	while (scanf("%u", &n), n){
		unsigned a[2] = {0};
		bool b = false;

		for (int i = 0; i < 32; i++){
			if (n & (1<<i)){
				a[b] |= (1<<i);
				b = !b;
			}
		}

		printf("%u %u\n", a[0], a[1]);
	}
}
