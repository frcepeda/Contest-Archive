#include <stdio.h>
#include <stdbool.h>

int a, b;
int dx, dy;
char str[110];

int abs(int a){
	return a >= 0 ? a : -a;
}

int sign(int x){
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else
		return -1;
}

bool check(int x, int y){
	int xdiff = a - x;
	int ydiff = b - y;

	if (x == a && y == b)
		return true;

	if (a != x && dx == 0)
		return false;
	if (b != y && dy == 0)
		return false;

	if (sign(xdiff) * sign(dx) < 0 || sign(ydiff) * sign(dy) < 0)
		return false;

	if (dx == 0)
		return abs(ydiff) % abs(dy) == 0;
	else if (dy == 0)
		return abs(xdiff) % abs(dx) == 0;
	else
		return 
			abs(ydiff) % abs(dy) == 0 &&
			abs(xdiff) % abs(dx) == 0 &&
			((long long int)xdiff) * dy == ((long long int)ydiff) * dx;
}

int main(void){
	int i, j;

	scanf("%d %d", &a, &b);
	scanf("%s", str);

	for (i = 0; str[i]; i++){
		if (str[i] == 'U')
			dy++;
		else if (str[i] == 'D')
			dy--;
		else if (str[i] == 'R')
			dx++;
		else if (str[i] == 'L')
			dx--;
	}

	int x = 0, y = 0;
	bool works = check(0,0);

	for (i = 0; !works && str[i]; i++){
		if (str[i] == 'U')
			y++;
		else if (str[i] == 'D')
			y--;
		else if (str[i] == 'R')
			x++;
		else if (str[i] == 'L')
			x--;
		works = check(x,y);
	}

	printf("%s\n", works ? "Yes" : "No");

	return 0;
}
