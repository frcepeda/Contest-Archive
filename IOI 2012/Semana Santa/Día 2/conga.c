#include <stdio.h>
#define MAXNUM 1000000

int linePos[MAXNUM];

int main(void){
	long long int total = 0;
	int i;
	int count;

	scanf("%d", &count);

	for (i = 0; i < count; i++){
		scanf("%d", &linePos[i]);
	}

	int center, last;

	if (count % 2 == 0){
		center = (linePos[count/2] + linePos[count/2 - 1]) / 2 + 1;
	} else {
		center = linePos[count/2];
	}
	
	last = center;
	for (i = (count/2) - 1; i >= 0; i--){
		total += last - linePos[i] - 1;
		last--;
	}

	last = center - (count%2 == 0? 1 : 0);
	for (i = (count/2) + (count%2 == 0? 0 : 1); i < count; i++){
		total += linePos[i]-last-1;
		last++;
	}

	printf("%lld\n", total);

	return 0;
}

