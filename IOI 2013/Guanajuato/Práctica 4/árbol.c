#include <stdio.h>
#include <strings.h>

#define MAXN 11
#define MAXCOUNT 51
#define MAXDIGITS 250

int chooseHalf[] = {1, 0, 2, 0, 6, 0, 20, 0, 70, 0, 252};
int chooseThree[] = {1, 0, 0, 6, 0, 0, 90, 0, 0, 1680, 0};

unsigned char dp[2][MAXCOUNT][MAXCOUNT][MAXCOUNT][MAXDIGITS];
unsigned char tmp[MAXDIGITS];
int N, R, V, A;

unsigned char max(unsigned char a, unsigned char b){
	return a > b ? a : b;
}

void add(unsigned char to[MAXDIGITS], unsigned char from[MAXDIGITS]){
	int i;
	unsigned long long int t = 0;
	to[0] = from[0] = max(to[0], from[0]);
	for (i = 1; i <= to[0] || t; i++){
		t += to[i] + from[i];
		to[i] = t % 10;
		t /= 10;
	}
	to[0] = i-1;
}

void multiply(unsigned char num[MAXDIGITS], int c){
	int i;
	unsigned long long int t = 0;
	memset(tmp, 0, sizeof(tmp));

	for (i = 1; i <= num[0] || t; i++){
		t += num[i] * c;
		tmp[i] = t % 10;
		t /= 10;
	}
	tmp[0] = i-1;
}

int main(void){
	int i, r, v, a;

	scanf("%d %d %d %d", &N, &R, &V, &A);

	for (r = 0; r <= R; r++){
		for (v = 0; v <= V; v++){
			for (a = 0; a <= A; a++){
				dp[0][r][v][a][0] = dp[0][r][v][a][1] = 1;
			}
		}
	}

	for (i = 1; i <= N; i++){
		for (r = 0; r <= R; r++){
			for (v = 0; v <= V; v++){
				for (a = 0; a <= A; a++){
					memset(dp[i%2][r][v][a], 0, sizeof(dp[i%2][r][v][a]));
					dp[i%2][r][v][a][0] = 1;

					if (r >= i)
						add(dp[i%2][r][v][a], dp[(i-1)%2][r-i][v][a]);
					if (v >= i)
						add(dp[i%2][r][v][a], dp[(i-1)%2][r][v-i][a]);
					if (a >= i)
						add(dp[i%2][r][v][a], dp[(i-1)%2][r][v][a-i]);

					if (i % 2 == 0){
						if (r >= i/2 && v >= i/2){
							multiply(dp[(i-1)%2][r-i/2][v-i/2][a], chooseHalf[i]);
							add(dp[i%2][r][v][a], tmp);
						}

						if (v >= i/2 && a >= i/2){
							multiply(dp[(i-1)%2][r][v-i/2][a-i/2], chooseHalf[i]);
							add(dp[i%2][r][v][a], tmp);
						}

						if (r >= i/2 && a >= i/2){
							multiply(dp[(i-1)%2][r-i/2][v][a-i/2], chooseHalf[i]);
							add(dp[i%2][r][v][a], tmp);
						}
					}

					if (i % 3 == 0 && r >= i/3 && v >= i/3 && a >= i/3){
						multiply(dp[(i-1)%2][r-i/3][v-i/3][a-i/3], chooseThree[i]);
						add(dp[i%2][r][v][a], tmp);
					}
				}
			}
		}
	}

	for (i = dp[N%2][R][V][A][0]; i >= 1; i--)
		printf("%c", '0' + dp[N%2][R][V][A][i]);
	printf("\n");

	return 0;
}
