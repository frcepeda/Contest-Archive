#include <stdio.h>

int t;
float l, w, d, m;

int main(void){
	int total = 0;

	scanf("%d", &t);

	while (t--){
		scanf("%f %f %f %f", &l, &w, &d, &m);
		int works = ((l <= 56 && w <= 45 && d <= 25) || l+w+d <= 125) && m <= 7;
		printf("%d\n", works);
		total += works;
	}

	printf("%d\n", total);

	return 0;
}
