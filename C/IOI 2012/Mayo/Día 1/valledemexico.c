#include <stdio.h>

#define MAXNUM 1000+1
#define magic(i) (i == num+1 ? 1 : (i == 0 ? num : i))

int num;

int agreement[MAXNUM][MAXNUM];

int memLeft[MAXNUM][MAXNUM];
int visLeft[MAXNUM][MAXNUM];

int memRight[MAXNUM][MAXNUM];
int visRight[MAXNUM][MAXNUM];

int left(int, int);
int right(int, int);
void reconstructRight(int, int);
void reconstructLeft(int, int);

int right(int a, int b){
	if (visRight[a][b])
		return memRight[a][b];

	visRight[a][b] = 1;

	if (a == b)
		return memRight[a][b] = 1;

	return memRight[a][b] = ( agreement[b][magic(b+1)] && right(a, magic(b+1)) ) ||
				( agreement[a][b] && left(magic(b+1), a) );
}

int left(int a, int b){
	if (visLeft[a][b])
		return memLeft[a][b];

	visLeft[a][b] = 1;

	if (a == b)
		return memLeft[a][b] = 1;

	return memLeft[a][b] = ( agreement[b][magic(b-1)] && left(a, magic(b-1)) ) ||
				( agreement[a][b] && right(magic(b-1), a) );
}

int temp[MAXNUM];
int tempIdx;

void reconstructRight(int a, int b){
	temp[tempIdx++] = b;
	if ( agreement[b][magic(b+1)] && right(a, magic(b+1)) ){ 
		if (a != b)
			reconstructRight(a, magic(b+1));
	} else if ( agreement[a][b] && left(magic(b+1), a) ){
		if (a != b)
			reconstructLeft(magic(b+1), a);
	}
}

void reconstructLeft(int a, int b){
	temp[tempIdx++] = b;
	if ( agreement[b][magic(b-1)] && left(a, magic(b-1)) ) {
		if (a != b)
			reconstructLeft(a, magic(b-1));
	} else if ( agreement[a][b] && right(magic(b-1), a) ){
		if (a != b)
			reconstructRight(magic(b-1), a);
	}
}

void printNormally(void){
	int i;
	for (i = 0; i < tempIdx; i++)
		printf("%d\n", temp[i]);
	tempIdx = 0;
}

void printInReverse(void){
	int i;
	for (i = tempIdx-1; i > 0 /* don't print j two times */; i--)
		printf("%d\n", temp[i]);
	tempIdx = 0;
}

int printAnswer(int a, int b){
	reconstructLeft(magic(a+1), b);
	printInReverse();
	reconstructRight(a, b);
	printNormally();
}

int main(void){
	int i,j;

	scanf("%d", &num);
	
	int temp;

	scanf("%d", &temp);

	while (temp--){
		scanf("%d %d", &i, &j);
		agreement[i][j] = agreement[j][i] = 1;
	}

	for (i = 1; i <= num; i++){
		for (j = 1; j <= num; j++){
			if (i == j) continue;

			if (right(i,j) && left(magic(i+1),j)){
				printAnswer(i,j);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;
}

