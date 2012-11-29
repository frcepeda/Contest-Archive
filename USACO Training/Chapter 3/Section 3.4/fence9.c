/*
    ID: frceped1
    LANG: C
    TASK: fence9
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("fence9.in", "r", stdin); freopen("fence9.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int gcd(int a, int b){
	int t;

	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}

	return a;
}

int triangle(int width, int height){
	int ret = (width - 1) * (height - 1);
	ret -= gcd(width, height) - 1;
	ret /= 2;
	return ret;
}

int main(void){
	openFiles();

	int n, m, p, answer;

	scanf("%d %d %d", &n, &m, &p);

	answer = triangle(n, m);

	if (n < p){
		answer += m - 1;
		answer += triangle(p-n, m);
	} else if (n > p){
		answer -= triangle(n-p, m);
		answer -= gcd(n-p, m) - 1;
	}

	printf("%d\n", answer);

	return 0;
}
