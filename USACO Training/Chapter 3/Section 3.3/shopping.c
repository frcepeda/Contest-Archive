/*
    ID: frceped1
    LANG: C
    TASK: shopping
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("shopping.in", "r", stdin); freopen("shopping.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define INF (1<<30)

typedef struct {
	int id, count;
} item;

typedef struct {
	int count[1000];
	int price;
} offer;

int min(int a, int b){
	return a < b ? a : b;
}

int mem[6][6][6][6][6];
item needed[5];
offer offers[110];

bool willPurchase[1000];

int S, B;

int search(int a, int b, int c, int d, int e){
	if (a < 0 || b < 0 || c < 0 || d < 0 || e < 0)
		return INF;
	if (!a && !b && !c && !d && !e)
		return 0;
	if (mem[a][b][c][d][e])
		return mem[a][b][c][d][e];
	mem[a][b][c][d][e] = INF;

	int i;
	for (i = 0; i < S; i++)
		mem[a][b][c][d][e] = min(mem[a][b][c][d][e], search(a - offers[i].count[needed[0].id],
									b - offers[i].count[needed[1].id],
									c - offers[i].count[needed[2].id],
									d - offers[i].count[needed[3].id],
									e - offers[i].count[needed[4].id]) + offers[i].price);
	
	return mem[a][b][c][d][e];
}

int main(void){
	openFiles();

	int i, j, k, l;

	scanf("%d", &S);

	for (i = 0; i < S; i++){
		scanf("%d", &j);
		while (j--){
			scanf("%d %d", &l, &k);
			offers[i].count[l] = k;
		}
		scanf("%d", &offers[i].price);
	}

	scanf("%d", &B);

	for (i = 0; i < B; i++){
		scanf("%d %d", &needed[i].id, &needed[i].count);
		scanf("%d", &offers[S].price);
		offers[S++].count[needed[i].id] = 1;
		willPurchase[needed[i].id] = true;
	}

	for (i = 0, k = 0; i < S; i++){
		bool something = false;
		for (j = 0; j < B; j++)
			if (offers[i].count[needed[j].id])
				something = true;
		if (something)
			offers[k++] = offers[i];
	}
	S = k;

	printf("%d\n", search(needed[0].count, needed[1].count, needed[2].count, needed[3].count, needed[4].count));

	return 0;
}
