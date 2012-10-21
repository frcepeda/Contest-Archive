#include <stdio.h>
#include <stdbool.h>

#define MAXN 1010

int N;
int possibleCount = 3;

bool possible[3] = {true, true, true};
char *name[3] = {"Pila", "Cola", "Prioridad"};

#define push(struct, n) push##struct(n)
#define pop(struct) pop##struct()

int queue[MAXN];
int qs, qe;

void pushqueue(int n){
	queue[qe++] = n;
}

int popqueue(void){
	if (qs < qe)
		return queue[qs++];
	return -123456;
}

int stack[MAXN];
int nextstack;

void pushstack(int n){
	stack[nextstack++] = n;
}

int popstack(void){
	if (nextstack > 0)
		return stack[--nextstack];
	return -123456;
}

int priority[MAXN];
int nextpriority;

#define parent(a) ((a-1)/2)
#define childA(a) (a*2+1)
#define childB(a) (a*2+2)

void pushpriority(int n){
	int curr = nextpriority++;

	while (curr){
		if (n > priority[parent(curr)]){
			priority[curr] = priority[parent(curr)];
			curr = parent(curr);
		} else break;
	}

	priority[curr] = n;
}

int poppriority(void){
	if (nextpriority <= 0)
		return -123456;

	int ret = priority[0];
	int curr = 0;
	int save = --nextpriority;

	while (childA(curr) < nextpriority){
		int swapchild;
		if (childB(curr) >= nextpriority || priority[childA(curr)] > priority[childB(curr)])
			swapchild = childA(curr);
		else
			swapchild = childB(curr);
		if (priority[swapchild] > priority[save]){
			priority[curr] = priority[swapchild];
			curr = swapchild;
		} else break;
	}

	priority[curr] = priority[save];
	return ret;
}

int main(void){
	int type, n;

	scanf("%d", &N);

	while (N--){
		scanf("%d %d", &type, &n);

		if (type == 1){
			if (possible[0])
				push(stack, n);
			if (possible[1])
				push(queue, n);
			if (possible[2])
				push(priority, n);
		} else {
			if (possible[0] && pop(stack) != n){
				possible[0] = false;
				possibleCount--;
			}
			if (possible[1] && pop(queue) != n){
				possible[1] = false;
				possibleCount--;
			}
			if (possible[2] && pop(priority) != n){
				possible[2] = false;
				possibleCount--;
			}
		}
	}

	if (possibleCount > 1){
		printf("Ambiguo\n");
	} else if (possibleCount == 0){
		printf("Imposible\n");
	} else {
		for (n = 0; n < 3; n++){
			if (possible[n]){
				printf("%s\n", name[n]);
				break;
			}
		}
	}

	return 0;
}

