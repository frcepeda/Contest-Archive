// Accepted
#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 3010

int n, seq[MAXN];
int diffs[MAXN];

int abs(int x){
	return x >= 0 ? x : -x;
}

int main(){
	int i;
	while (scanf("%d", &n) != EOF){
		for (i = 0; i < n; i++)
			scanf("%d", &seq[i]);
		for (i = 1; i < n; i++)
			diffs[i-1] = abs(seq[i] - seq[i-1]);

		sort(diffs, diffs+n-1);

		for (i = 0; i < n-1; i++)
			if (diffs[i] != i+1)
				break;

		if (i == n-1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}
}
