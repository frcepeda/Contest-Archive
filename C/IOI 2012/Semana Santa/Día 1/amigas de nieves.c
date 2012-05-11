#include <stdio.h>

#define MAXBOYS 10
#define MAXGIRLS 20

int boys[MAXBOYS];
int girls[MAXGIRLS];

int visitedBoys[1<<MAXBOYS];
int visitedGirls[1<<MAXGIRLS];

int boyNum, girlNum;

int answer;

void try(int usedBoys, int usedGirls, int pairs){
	if (visitedBoys[usedBoys] || visitedGirls[usedGirls]) return;
	visitedBoys[usedBoys] = 1;
	visitedGirls[usedGirls] = 1;
	if (pairs > answer) answer = pairs;
	int i, j;
	for (i = 1; i <= boyNum; i++){
		if (usedBoys & 1<<i) continue;
		for (j = 1; j <= girlNum; j++){
			if (usedGirls & 1<<j) continue;
			if (boys[i] & 1<<j && girls[j] & 1<<i)
				try(usedBoys|1<<i, usedGirls|1<<j, pairs+1);
		}
	}
}

int main(void){
	int i;

	scanf("%d %d", &boyNum, &girlNum);

	if (boyNum < girlNum){
		for (i = 1; i <= boyNum; i++){
			int girl, count;
			scanf("%d", &count);
			while (count--){
				scanf("%d", &girl);
				boys[i] |= 1<<girl;
			}
		}
		for (i = 1; i <= girlNum; i++){
			int boy, count;
			scanf("%d", &count);
			while (count--){
				scanf("%d", &boy);
				girls[i] |= 1<<boy;
			}
		}
	} else {
		for (i = 1; i <= boyNum; i++){
			int girl, count;
			scanf("%d", &count);
			while (count--){
				scanf("%d", &girl);
				girls[i] |= 1<<girl;
			}
		}
		for (i = 1; i <= girlNum; i++){
			int boy, count;
			scanf("%d", &count);
			while (count--){
				scanf("%d", &boy);
				boys[i] |= 1<<boy;
			}
		}
		int temp = girlNum;
		girlNum = boyNum;
		boyNum = temp;
	}

	try(0,0,0);
	printf("%d\n", answer);

	return 0;
}

