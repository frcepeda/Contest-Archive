/*
    ID: frceped1
    LANG: C
    TASK: contact
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("contact.in", "r", stdin); freopen("contact.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define MAXLENGTH 13
#define MAXSTRINGS (1<<12)
#define MAXSTRING 200010

typedef struct {
	int count, num, length;
} answer;

answer makeAnswer(int count, int num, int length){
	answer a = {count, num, length};
	return a;
}

int intCmp(int a, int b){
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	return 0;
}

int ansCmp(const void *a, const void *b){
	int ret;
	if ((ret = -intCmp(((answer *)a)->count, ((answer *)b)->count)))
		return ret;
	if ((ret = intCmp(((answer *)a)->length, ((answer *)b)->length)))
		return ret;
	return intCmp(((answer *)a)->num, ((answer *)b)->num);
}

answer ans[MAXLENGTH*MAXSTRINGS];
int nextAns;

void printBaseTwo(int num, int count){
	if (count == 0) return;
	printBaseTwo(num >> 1, count - 1);
	printf("%d", num & 1);
}

int count[MAXLENGTH][MAXSTRINGS];

bool string[MAXSTRING];
int stringLength;

int A, B, N;

int main(void){
	openFiles();
	
	int i, j, tmp;

	scanf("%d %d %d", &A, &B, &N);

	char c;
	while ((c = getchar()) != EOF)
		if (isdigit(c))
			string[stringLength++] = c == '1';

	for (i = A; i <= B; i++){
		tmp = 0;
		for (j = 0; j < i-1; j++){
			tmp <<= 1;
			tmp |= string[j];
		}
		for (; j < stringLength; j++){
			tmp <<= 1;
			tmp |= string[j];
			tmp &= (1<<i)-1;
			count[i][tmp]++;
		}
	}

	for (i = A; i <= B; i++)
		for (j = 0; j < 1<<i; j++)
			if (count[i][j])
				ans[nextAns++] = makeAnswer(count[i][j], j, i);	

	qsort(ans, nextAns, sizeof(answer), ansCmp);

	int count;
	for (i = 0; i < nextAns && N; N--, i++){
		printf("%d\n", ans[i].count);
		for (j = i, count = 0; j < nextAns && ans[j].count == ans[i].count; j++, count++){
			printBaseTwo(ans[j].num, ans[j].length);
			putchar(ans[j+1].count != ans[j].count || (count && (count + 1) % 6 == 0) ? '\n' : ' ');
		}
		i = j-1;
	}

	return 0;
}
