// 100/100 points
#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define MAXN 1000100
#define MAXE 50

int max(int a, int b) { return a > b ? a : b; }

int N, E;
char _str[MAXN], ex[MAXE];

int _strlen, next;

int str(int x){
	for (; x >= _strlen && next < N; _strlen++, next++)
		_str[_strlen] = _str[next];

	if (x < _strlen)
		return _str[x];

	if (_strlen == 0)
		printf("FRULA");
	else
		for (x = 0; x < _strlen; x++)
			putchar(_str[x]);

	putchar('\n');

	exit(0);
}

int main(void){
	int i, j;

	scanf("%s", _str);
	scanf("%s", ex);

	N = strlen(_str);
	E = strlen(ex);

	i = 0;
	while (1){
		for (j = 0; j < E && str(i+j) == ex[j]; j++);

		if (j == E){
			_strlen -= E;
			i = max(0, i - E);
		} else i++;
	}

	return 1;
}
