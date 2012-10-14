#include <stdio.h>

#define MAXNUM 1000000+1
#define DIF 5
#define MIN 3
#define MAX 5

int dp[MAXNUM][DIF][DIF][DIF];
char string[MAXNUM];

int fMIN(int a, int b) { return a < b ? a : b; };
int fMAX(int a, int b) { return a > b ? a : b; };

int main(void){
	int length, mod;
	int i, dif, min, max;

	scanf("%d", &length);
	scanf("%d\n", &mod);
	scanf("%s", string);

	for (min = 0; min < MIN; min++){
		for (max = 2; max-min <= 2; max++){
			for (dif = min; dif <= max; dif++){
				dp[length][dif][min][max] = 1;
			}
		}
	}

	for (i = length-1; i >= 0; i--){
		for (min = 0; min < MIN; min++){
			for (max = 2; max-min <= 2; max++){
				for (dif = 0; dif < DIF; dif++){
					if (dif > 0 && dif < MAX){
						dp[i][dif][min][max] = dp[i+1][dif+1][min][fMAX(max, dif+1)] +
									dp[i+1][dif-1][fMIN(min, dif-1)][max];
					} else if (dif > 0) {
						dp[i][dif][min][max] = dp[i+1][dif-1][fMIN(min, dif-1)][max];
					} else {
						dp[i][dif][min][max] = dp[i+1][dif+1][min][fMAX(max, dif+1)];
					}
					dp[i][dif][min][max] %= mod;
				}
			}
		}
	}

	int ans = 1;
	dif = min = max = 2;

	for (i = 0; i < length; i++){
		if (string[i] == 'P'){
			ans += dp[i+1][dif-1][fMIN(min, dif-1)][max];
			ans %= mod;
			dif++;
			max = fMAX(max, dif);
		} else {
			dif--;
			min = fMIN(min, dif);
		}
	}

	printf("%d\n", ans);

	return 0;
}

