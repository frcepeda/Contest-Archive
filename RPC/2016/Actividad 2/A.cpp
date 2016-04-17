#include <algorithm>

using namespace std;

int N, B, T;

int main(){
	while (scanf("%d %d %d", &N, &B, &T) == 3){
		int b = 0, t = 0, x = 0, y = 0, z;

		while (N || b || t){
			if (b == 0){
				z = min(B, N);
				b += z;
				N -= z;
			} else {
				b--; x++;
			}

			if (t == 0){
				z = min(T, N);
				t += z;
				N -= z;
			} else {
				t--; y++;
			}
		}

		printf("%d %d\n", x, y);
	}
}
