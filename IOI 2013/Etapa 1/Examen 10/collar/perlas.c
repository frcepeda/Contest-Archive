#include "main.h"
#include "perlas.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAXN 1010
#define MAXLIST 110

static bool dp[MAXN][MAXN];
static short move[MAXN][MAXN];

static bool team[MAXN];
static short listLen[MAXN][2];
static short list[MAXN][2][MAXLIST];
static int N, L;

static char collar[MAXN];

static void reverseString(char *str){
	char *end = str + strlen(str) - 1;
	char t;

	for (; str < end; str++, end--){
		t = *str;
		*str = *end;
		*end = t;
	}
}

void juega(void){
	int i, j, k, currPlayer;

	scanf("%d %d %d", &L, &N, &currPlayer);
	scanf("%s", collar);
	reverseString(collar);
	
	for (i = 1; i <= N; i++){
		scanf("%d", &j);
		team[i] = !!j;

		scanf("%hd", &listLen[i][0]);
		for (j = 0; j < listLen[i][0]; j++)
			scanf("%hd", &list[i][0][j]);

		scanf("%hd", &listLen[i][1]);
		for (j = 0; j < listLen[i][1]; j++)
			scanf("%hd", &list[i][1][j]);
	}

	for (i = 1; i <= N; i++)
		dp[0][i] = team[i];

	for (i = 1; i < L; i++){
		for (j = 1; j <= N; j++){
			if (team[j]){
				dp[i][j] = false;
				for (k = 0; k < listLen[j][collar[i] == 'B']; k++){
					if (dp[i-1][list[j][collar[i] == 'B'][k]] > dp[i][j]){
						dp[i][j] = true;
						move[i][j] = list[j][collar[i] == 'B'][k];
						break;
					}
				}
			} else {
				dp[i][j] = true;
				for (k = 0; k < listLen[j][collar[i] == 'B']; k++){
					if (dp[i-1][list[j][collar[i] == 'B'][k]] < dp[i][j]){
						dp[i][j] = false;
						move[i][j] = list[j][collar[i] == 'B'][k];
						break;
					}
				}
			}
		}
	}

	for (i = L-1; i > 0; i--){
		if (team[currPlayer]){
			currPlayer = recibeCollar();
		} else {
			currPlayer = move[i][currPlayer];
			pasaCollar(currPlayer);
		}
	}

	termina();
}
                                        
