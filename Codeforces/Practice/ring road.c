#include <stdio.h>
#include <stdbool.h>

#define MAXN 110

int n, sum, oneWay;

int connected[MAXN][2];
int cost[MAXN][2];
bool dir[MAXN][2];

int min(int a, int b){
	return a < b ? a : b;
}

void add(int a, int b, int c,bool d){
	int i = connected[a][0] != 0;
	connected[a][i] = b;
	cost[a][i] = c;
	dir[a][i] = d;
}

int main(void){
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		sum += c;
		add(a,b,c,true);
		add(b,a,c,false);
	}

	bool first = true;
	int last = -1;
	bool d;
	i = 1;

	while (i != 1 || first){
		if (first)
			first = false;
		d = connected[i][0] == last;

		if (dir[i][d])
			oneWay += cost[i][d];

		last = i;
		i = connected[i][d];
	}

	printf("%d\n", min(oneWay, sum - oneWay));

	return 0;
}
