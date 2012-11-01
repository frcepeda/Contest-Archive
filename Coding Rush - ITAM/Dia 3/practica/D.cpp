#include <stdio.h>

int stack[10000];
int nextStack;

int main(){
	char c;
	int id, i;

	while ((c = getchar()) != EOF){
		while (c != 'D' && c != 'P' && c != 'T'){
			c = getchar();
			if (c == EOF)
				break;
		}
		switch (c){
			case 'T':
				nextStack--;
				break;
			case 'D':
				scanf("%d", &id);
				stack[nextStack++] = id;
				break;
			case 'P':
				scanf("%d", &id);
				i = nextStack - 1;
				while (stack[i] != id)
					i--;
				printf("%d\n", nextStack - i - 1);
				break;
		}
	}

	return 0;
}
