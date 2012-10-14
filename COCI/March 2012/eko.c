#include <stdio.h>

#define MAXTREES 1000000

int trees[MAXTREES];
int treeNum, required;

long long int cutTrees(int height){
	long long int tot = 0;
	int i;
	for (i = 0; i < treeNum; i++){
		if (trees[i] > height)
			tot += trees[i] - height;
	}
	return tot;
}

int main(int argc, const char * argv[])
{
	int i;
	scanf("%d %d", &treeNum, &required);
	for (i = 0; i < treeNum; i++)
		scanf("%d", &trees[i]);
	int hi = 1000000000, lo = 0;
	int lastBest = 0;
	while (lo <= hi){
		int mid = (hi + lo) / 2;
		if (cutTrees(mid) >= required){
			lo = mid + 1;
			if (lastBest < mid)
				lastBest = mid;
		} else
			hi = mid - 1;
	}
	printf("%d\n", lastBest);		
}