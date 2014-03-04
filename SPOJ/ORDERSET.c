#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXN 200100
#define MAXL 18

typedef struct {
	int key, height;
	int next[MAXL], len[MAXL];
} elem;

elem skip[MAXN];
int nextElem = 2; // 0 -> NIL, 1 -> start

void initskip(){
	int i;
	for (i = 0; i < MAXL; i++)
		skip[1].len[i] = 1;
	skip[0].key = 1<<30;
	skip[0].height = MAXL;
	skip[1].height = MAXL;
}

int newHeight(void){
	int h = 1, x;
	for (x = rand(); h < MAXL && x % 2; x /= 2)
		h++;
	return h;
}

int newElem(int key){
	skip[nextElem].key = key;
	skip[nextElem].height = newHeight();
	return nextElem++;
}

int search(int key){
	int curr = 1, i;

	for (i = MAXL-1; i >= 0; i--)
		while(key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];

	curr = skip[curr].next[0];

	return skip[curr].key == key ? curr : 0;
}

int isInside(int key){
	return search(key) != 0;
}

int kthItem(int k){
	int curr = 1, i;

	for (i = MAXL-1; i >= 0 && k > 0; i--)
		while (curr && k >= skip[curr].len[i]){
			k -= skip[curr].len[i];
			curr = skip[curr].next[i];
		}

	return curr;
}

int countBefore(int key){
	int curr = 1, i, k = 0;

	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key){
			k += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
	}

	return k;
}

void insert(int key){
	int curr = 1, i;
	int prev[MAXL], jumps[MAXL] = {0};

	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key){
			jumps[i] += skip[curr].len[i];
			curr = skip[curr].next[i];
		}
		prev[i] = curr;
	}

	if (skip[skip[prev[0]].next[0]].key == key) return;

	int e = newElem(key);

	for (i = 0; i < MAXL; i++){
		if (i < skip[e].height){
			int oldLen = skip[prev[i]].len[i];
			skip[prev[i]].len[i] = i == 0 ? 1 : jumps[i-1] + skip[prev[i-1]].len[i-1];
			skip[e].len[i] = oldLen - skip[prev[i]].len[i] + 1;

			skip[e].next[i] = skip[prev[i]].next[i];
			skip[prev[i]].next[i] = e;
		} else skip[prev[i]].len[i]++;
	}
}

void delete(int key){
	int curr = 1, i;

	if (!isInside(key)) return;

	for (i = MAXL-1; i >= 0; i--){
		while (key > skip[skip[curr].next[i]].key)
			curr = skip[curr].next[i];

		if (skip[skip[curr].next[i]].key == key){
			skip[curr].len[i] += skip[skip[curr].next[i]].len[i];
			skip[curr].next[i] = skip[skip[curr].next[i]].next[i];
		}

		skip[curr].len[i]--;
	}
}

int Q;

int main(void){
	initskip();

	scanf("%d\n", &Q);

	while (Q--){
		char q;
		int a;

		scanf("%c %d\n", &q, &a);

		if (q == 'I')
			insert(a);
		else if (q == 'D')
			delete(a);
		else if (q == 'K'){
			a = kthItem(a);
			if (a != 0)
				printf("%d\n", skip[a].key);
			else
				printf("invalid\n");
		} else if (q == 'C')
			printf("%d\n", countBefore(a));
	}

	return 0;
}
