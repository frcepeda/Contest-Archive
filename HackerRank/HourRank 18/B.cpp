#include <cstdio>
#include <algorithm>

using namespace std;

char s[100100];
int a[6], b[6];

int main(){
	scanf("%s", s);

	int ans = 0, acc = 0;

	a[0] = s[0] != '0';

	for (int i = 0; s[i] != '\0'; i++){
		acc = (s[i] - '0' + 10 * acc) % 6;
		for (int j = 0; j < 6; j++)
			b[j] = 0;
		for (int j = 0; j < 6; j++)
			b[10*j%6] += a[j];
		for (int j = 0; j < 6; j++)
			a[j] = b[j];
		ans += a[acc];
		if (s[i] == '0') ans++;
		if (s[i+1] != '0') a[acc]++;
	}

	printf("%d\n", ans);
}
