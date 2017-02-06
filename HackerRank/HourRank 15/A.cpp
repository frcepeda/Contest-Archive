#include <cstdio>
#include <algorithm>

using namespace std;

int q, x, y, z;

int main(){
	scanf("%d", &q);

	while (q--){
		scanf("%d %d %d", &x, &y, &z);

		int da = abs(x - z);
		int db = abs(y - z);

		if (da == db)
			printf("Mouse C\n");
		else if (da < db)
			printf("Cat A\n");
		else
			printf("Cat B\n");
	}
}
