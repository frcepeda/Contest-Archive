#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 1000100

using namespace std;

int d[4] = {1,6,8,9};
int N;
char num[MAXN];

int main(){
	int i, j, k;

	scanf("%s", num);
	N = strlen(num);

	for (j = 0; j < 4; j++){
		for (i = 0; i < N && num[i] != d[j]+'0'; i++);
		swap(num[i], num[N-j-1]);
	}
	num[N-4] = '\0';

	j = 0;
	k = 1;
	for (i = 0; i < N-4; i++){
		j = (j*10 + num[i] - '0') % 7;
		k = (k*10) % 7;
	}
	j = (7 - j) % 7;

	do {
		if ((((d[0]*10 + d[1])*10 + d[2])*10 + d[3])*k % 7 == j){
			printf("%d%d%d%d%s\n", d[0], d[1], d[2], d[3], num);
			return 0;
		}
	} while (next_permutation(d,d+4));

	printf("0\n");
}
