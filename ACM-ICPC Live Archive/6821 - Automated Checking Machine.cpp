#include <stdio.h>

int a[5], b[5];
int main(){
	int i;
	for (i = 0; i < 5; i++) scanf("%d", &a[i]);
	for (i = 0; i < 5; i++) scanf("%d", &b[i]);
	for (i = 0; i < 5; i++) if (a[i] == b[i]) break;
	printf("%c\n", i < 5 ? 'N' : 'Y');
}
