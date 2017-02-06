#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;
int n, p[maxn];
bool np[maxn];

int main(){
	for (int i = 4; i < maxn; i += 2)
		np[i] = true;
	for (int i = 3; i*i < maxn; i += 2)
		if (!np[i])
			for (int j = i*i; j < maxn; j += i)
				np[j] = true;

	for (int i = 2; i < maxn; i++)
		p[i] += !np[i] + p[i-1];

	int k;
	scanf("%d", &k);

	while (k--){
		scanf("%d", &n);
		printf("%s\n", p[n] % 2 ? "Alice" : "Bob");
	}
}
