// Accepted
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int T;
int N, explen;
char expr[510], nums[510];

long long plus[10], minus[10];
long long tenpows[10];

void count(){
	int i = 0, sign = 1;
	if (expr[0] == '+'){
		i++;
	} else if (expr[0] == '-'){
		i++;
		sign = -1;
	}

	while (true){
		int cnt = 0;

		for (; expr[i] == '#'; i++)
			cnt++;

		if (sign == 1)
			plus[cnt]++;
		else
			minus[cnt]++;

		if (expr[i] == '+')
			sign = 1;
		else if (expr[i] == '-')
			sign = -1;
		else break;
		
		i++;
	}
}

int main(){
	tenpows[0] = 1;
	for (int i = 1; i < 10; i++)
		tenpows[i] = tenpows[i-1] * 10;

	scanf("%d", &T);

	while (T--){
		long long ans = 0;
		int i;

		for (i = 0; i < 10; i++)
			minus[i] = plus[i] = 0;

		scanf("%s", expr);
		scanf("%s", nums);
		explen = strlen(expr);
		N = strlen(nums);

		count();
		sort(nums, nums + N);

		for (i = 7; i >= 1; i--){
			minus[i] += minus[i+1];
			plus[i] += plus[i+1];
		}

		int l = 0;
		for (i = 7; i >= 1; i--)
			while (minus[i]--)
				ans -= tenpows[i-1] * (nums[l++] - '0');
		for (i = 1; i <= 7; i++)
			while (plus[i]--)
				ans += tenpows[i-1] * (nums[l++] - '0');

		printf("%lld\n", ans);
	}
}
