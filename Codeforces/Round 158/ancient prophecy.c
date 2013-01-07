#include <stdio.h>
#include <stdbool.h>

#define MAXN 100020

char str[MAXN];
char ans[40];
int date[35][12][4];
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int getNum(int idx, int n){
	int num = 0, i;
	for (i = idx; i < idx + n; i++)
		num = num * 10 + (str[i] - '0');
	return num;
}

int main(void){
	int i, j, k;

	fgets(str, MAXN, stdin);

	for (i = 0; str[i]; i++){
		if (str[i] == '-' && i >= 2 && str[i+8] && isdigit(str[i-1]) &&
				isdigit(str[i-2]) && isdigit(str[i+1]) && isdigit(str[i+2]) && 
				str[i+3] == '-' && isdigit(str[i+4]) && isdigit(str[i+5]) &&
				isdigit(str[i+6]) && isdigit(str[i+7])){
			int year = getNum(i+4, 4);
			int month = getNum(i+1, 2);
			int day = getNum(i-2, 2);
			if (year >= 2013 && year <= 2015 && month >= 1 && month <= 12 && day >= 1 && day <= days[month])
				date[day][month][year-2013]++;
		}
	}

	int bestC = 0;

	for (i = 1; i <= 31; i++)
		for (j = 1; j <= 12; j++)
			for (k = 0; k <= 2; k++)
				if (bestC < date[i][j][k]){
					bestC = date[i][j][k];
					sprintf(ans, "%02d-%02d-%04d", i, j, k+2013);
				}

	printf("%s\n", ans);

	return 0;
}
