#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 200100

long long int answer = 1;
int permutation[MAXN];
bool visited[MAXN];
int p;

long long int lcm(long long int x, long long int y){
	return (y / __gcd(x,y)) * x;
}

int length(int x, int a){
	if (visited[x]) return a;
	visited[x] = true;
	return length(permutation[x], a+1);
}

int main(void) {
	int i, j;

	scanf("%d", &p);

	for (i = 1; i <= p/2; i++)
		permutation[i] = i * 2;
	for (i = 1; i <= p/2; i++)
		permutation[i+p/2] = i * 2 - 1;

	for (i = 1; i <= p; i++)
		if (!visited[i])
			answer = lcm(answer, length(i,0));

	printf("%lld\n", answer);
}
