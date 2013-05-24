#include <stdio.h>
#include <ctype.h>

#define MAXSTACK 410

int N;

#define push(x) stack[sti++] = (x)
#define pop() (stack[--sti])
#define peek() (stack[sti-1])
#define stackIsNotEmpty (sti)

char stack[MAXSTACK];
int sti;

int precedence[] = {['+'] = 1, ['-'] = 2, ['*'] = 3, ['/'] = 4, ['^'] = 5, ['('] = 0, [')'] = 0};

int main(void){
	char c;

	scanf("%d\n", &N);

	while (N--){
		while ((c = getchar()) != '\n'){
			if (isalpha(c)){
				putchar(c);
			} else if (c != '(' && c != ')'){
				while (stackIsNotEmpty && precedence[c] <= precedence[peek()])
					putchar(pop());
				push(c);
			} else if (c == '('){
				push(c);
			} else if (c == ')'){
				while (stackIsNotEmpty && peek() != '(')
					putchar(pop());
				pop();
			}
		}

		while (stackIsNotEmpty)
			putchar(pop());

		putchar('\n');
	}

	return 0;
}
