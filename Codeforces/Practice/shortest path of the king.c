#include <stdio.h>

// 0 -> column, 1 -> row

int start[2], end[2];

int max(int a, int b){
	return a > b ? a : b;
}

int abs(int a){
	return a >= 0 ? a : -a;
}

int main(void){
	int i, j;
	char str[10];

	scanf("%s", str);
	start[0] = str[0] - 'A';
	start[1] = str[1] - '0' - 1;

	scanf("%s", str);
	end[0] = str[0] - 'A';
	end[1] = str[1] - '0' - 1;

	printf("%d\n", max(abs(start[0] - end[0]), abs(start[1] - end[1])));

	while (start[0] != end[0] || start[1] != end[1]){
		if (start[0] < end[0]){
			putchar('R');
			start[0]++;
		} else if (start[0] > end[0]){
			putchar('L');
			start[0]--;
		}

		if (start[1] < end[1]){
			putchar('U');
			start[1]++;
		} else if (start[1] > end[1]){
			putchar('D');
			start[1]--;
		}

		putchar('\n');
	}

	return 0;
}
