/*
	 ID: frceped1
	 LANG: C
	 TASK: msquare
 */

#include <stdio.h>
#include <stdbool.h>

#define UPLOAD 1

#if UPLOAD
	#define openFiles() freopen("msquare.in", "r", stdin); freopen("msquare.out", "w", stdout)
#else
	#define openFiles()
#endif

// USACO upload macros

#define SQUARES 8
#define OPER 3
#define MAXSTATES 40320
#define MAXSTEPS MAXSTATES

typedef struct {
	int permutation, cost, parent;
	char operation;
} state;

char currOrdering[SQUARES], tmp[SQUARES];
int start = 0, goal;

char operNames[] = "ABC";
char operation[OPER][SQUARES] = {{8,7,6,5,4,3,2,1}, {4,1,2,3,6,7,8,5}, {1,7,2,4,5,3,6,8}};

int factorial[SQUARES+1];

/*
	So how's this work? I know it's gonna come in handy later, so I'll just leave this here.

	To get the permutation's index, it's convenient to use a "divide-and-conquer" method.

	First, you take the first element of the sequence in lexicographical order and see where
	it is in the permutation.  If there are N elements, then there are (N-1)! orderings in
	which one element is fixed into place, and since we chose the first element in
	lexicographical order, we can tell how "far" at least we are into the sequence of
	permutations.

	For example, if you have 4 elements and number 1 is in the 3rd position, it means that
	before this permutation there must've been at least 2*(4-1)! permutations before this one,
	because there are two earlier positions where number 1 could've been placed.

	You can then apply this algorithm to the permutation that would result by removing number 1
	from the original one, and keep doing this until you get to a size 1 permutation, while
	adding all of the previous answers to get the original permutation's index.

	As for this implementation, I don't actually delete the last number from the list, but
	just keep track of how many elements that are less than the "first" of the sequence whose
	index I'm computing and simply ignore them.

	Now, to get the actual permutation given an index, you (obviously) do the same in reverse.
	Since we kept adding to the result the next smaller permutation's index, and because they
	were obtained by multiplying the factorial function by a number that could never be
	greater than the it (because it was an index and the sequence could only get shorter),
	you can obtain the original indexes.

	Starting with 2, with which the first number wasn't multiplied (because 1! is just 1),
	you can obtain it with the modulo operation, since it was only added to the rest of the
	expression which was multiplied by 2.

	By dividing by 2, you have now a number which is added to an expression that was
	multiplied by 3, so you can obtain this number by using the modulo operation in the
	same manner as before, and keep doing this until you get the original indexes, except for
	the last one, but it will always be 0 because it's the only index that was left.
 */

void numberToPermutation(char *arr, int permutation){
	int i, j, count, perm[SQUARES+1] = {0}, base = 2;

	for (i = 0; i < SQUARES; i++)
		arr[i] = 0;

	for (i = SQUARES-1; i >= 0; i--, base++){
		perm[i] = permutation % base;
		permutation /= base;
	}

	for (i = 1; i <= SQUARES; i++){
		for (j = 0, count = perm[i]+1; count; j++){
			if (!arr[j]){
				count--;
				if (!count)
					break;
			}
		}
		arr[j] = i;
	}
}

int permutationNum(char *arr){
	unsigned int i, j, less, permutation = 0;

	for (i = 1; i < SQUARES; i++){
		for (less = 0, j = 0; j < SQUARES; j++){
			if (arr[j] < i)
				less++;
			else if (arr[j] == i)
				break;
		}
		permutation += (j - less)*factorial[SQUARES-i]; // count from the right
	}

	return permutation;
}

state queue[MAXSTATES];
int qs, qe;

#define push(a) queue[qe++] = (a)
#define pop() (queue[qs++])
#define queueIsNotEmpty (qs < qe)

bool visited[MAXSTATES];

state search(void){
	int i, j;
	state curr = {start, 0, -1}, next;
	push(curr);
	
	while (queueIsNotEmpty){
		curr = pop();

		if (curr.permutation == goal)
			return curr;

		numberToPermutation(currOrdering, curr.permutation);

		next.cost = curr.cost + 1;
		next.parent = qs-1;
		for (i = 0; i < OPER; i++){
			for (j = 0; j < SQUARES; j++)
				tmp[j] = currOrdering[operation[i][j] - 1];

			next.operation = operNames[i];
			next.permutation = permutationNum(tmp);

			if (!visited[next.permutation]){
				visited[next.permutation] = true;
				push(next);
			}
		}
	}
}

char steps[MAXSTEPS];

void getSteps(state curr){
	while (curr.cost > 0){
		steps[curr.cost-1] = curr.operation;
		curr = queue[curr.parent];
	}
}

int main(void){
	openFiles();

	int i;
	
	for (i = 0; i < SQUARES; i++){
		int t;
		scanf("%d", &t);
		tmp[i] = (char)t;
	}

	factorial[0] = 1;
	for (i = 1; i <= SQUARES; i++)
		factorial[i] = factorial[i-1] * i;

	goal = permutationNum(tmp);

	state end = search();
	printf("%d\n", end.cost);
	getSteps(end);

	for (i = 0; i < end.cost; i++)
		printf("%c%s", steps[i], (i+1) % 60 == 0 || (i+1) == end.cost ? "\n" : "");

	if (end.cost == 0)
		printf("\n");

	return 0;
}
