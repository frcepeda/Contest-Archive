/*
    ID: frceped1
    LANG: C
    TASK: sort3
 */

#include <stdio.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("sort3.in", "r", stdin); freopen("sort3.out", "w", stdout)
#else
	#define openFiles()
#endif

FILE *in, *out;

// USACO upload macros

#define MAXNUM 1000

int sequence[MAXNUM];
int length;

int count[4];

int answer;

int main(void){
	openFiles();

	int i;

	scanf("%d", &length);

	for (i = 0; i < length; i++){
		scanf("%d", &sequence[i]);
		count[sequence[i]]++;
	}

	int next = count[1];
	int back = length;

	for (i = 0; i < count[1]; i++){
		if (sequence[i] != 1){
			if (sequence[i] == 2){
				for (; next < length; next++){
					if (sequence[next] == 1){
						sequence[next] = 2;
						sequence[i] = 1;
						goto done;
					}
				}
			} else {
				for (; back >= 0; back--){
					if (sequence[back] == 1){
						sequence[back] = 3;
						sequence[i] = 1;
						goto done;
					}
				}
			}
		done:
			answer++;
		}
	}

	next = count[1] + count[2];
	
	for (i = count[1]; i < count[1] + count[2]; i++){
		if (sequence[i] != 2){
			for (; next < length; next++){
				if (sequence[next] == 2){
					sequence[next] = 3;
					sequence[i] = 2;
					goto done2;
				}
			}
		done2:
			answer++;
		}
	}

	printf("%d\n", answer);

	return 0;
}
