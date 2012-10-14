/*
    ID: frceped1
    LANG: C
    TASK: zerosum
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("zerosum.in", "r", stdin); freopen("zerosum.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

int N;
char sequence[1000];
int length;

char operations[3] = {' ', '+', '-'};

bool parseandtry(void){
	int i, tmp, acc;

	for (i = 0, acc = 0; sequence [i] && (sequence[i] < 10 || sequence[i] == ' '); i++){
		if (sequence[i] == ' ')
			continue;
		acc += sequence[i];
		acc *= 10;
	}
	acc /= 10;

	while (i < length){
		bool op = sequence[i++] == '+';
		for (tmp = 0; sequence[i] && (sequence[i] < 10 || sequence[i] == ' '); i++){
			if (sequence[i] == ' ')
				continue;
			tmp += sequence[i];
			tmp *= 10;
		}
		tmp /= 10;
		if (op){
			acc += tmp;
		} else {
			acc -= tmp;
		}
	}

	return acc == 0;
}

void try(int i){
	int j;

	if (i >= N) {
		sequence[length++] = i;
		if (parseandtry()){
			for (i = 0; i < length; i++){
				putchar(sequence[i] < 10 ? sequence[i]+'0' : sequence[i]);
			}
			printf("\n");
		}
		length--;
		return;
	}

	sequence[length++] = i;
	length++;
	for (j = 0; j < 3; j++){
		sequence[length-1] = operations[j];
		try(i+1);
	}
	length -= 2;
}

int main(void){
	openFiles();

	scanf("%d", &N);

	try(1);

	return 0;
}
