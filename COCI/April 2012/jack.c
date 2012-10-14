#include <stdio.h>

#define MAXCARDS 100

int cards[MAXCARDS];
int cardNum, maxNum;
int answer;

int main(void){
	int i, j, k;

	scanf("%d %d", &cardNum, &maxNum);

	for (i = 0; i < cardNum; i++)
		scanf("%d", &cards[i]);

	for (i = 0; i < cardNum; i++){
		for (j = i+1; j < cardNum; j++){
			for (k = j+1; k < cardNum; k++){
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= maxNum && sum > answer)
					answer = sum;
			}
		}
	}

	printf("%d\n", answer);

	return 0;
}

