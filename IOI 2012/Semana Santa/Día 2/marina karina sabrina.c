#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 100010

typedef struct {
	int parent, value, joined;
} node;

typedef struct {
	int value, index;
} seq;

seq sequence[MAXLENGTH];
int count;
node left[MAXLENGTH];
node right[MAXLENGTH];

int intCmp(int a, int b){
	if (a > b) return 1;
	if (b > a) return -1;
	return 0;
}

int seqCmp(const void *a, const void *b){
	return intCmp(((seq *)a)->value, ((seq *)b)->value);
}

int isJoined(node curr){
	return curr.joined;
}

node makeParent(int val){
	node n = {-1, val, 1};
	return n;
}

node joinAndReturn(node *arr, int index, int right){
	if (arr[index].parent == -1){
		if (right) {
			if (index < count && isJoined(arr[index+1]))
				return arr[index] = joinAndReturn(arr, index+1, right);
		} else {
			if (index > 0 && isJoined(arr[index-1]))
				return arr[index] = joinAndReturn(arr, index-1, right);
		}
		node temp = {index, arr[index].value, 1};
		return temp;
	} else {
		return arr[index] = joinAndReturn(arr, arr[index].parent, right);
	}
}

long long int doMagic(int index, int value){
	if (isJoined(right[index+1])){
		right[index] = joinAndReturn(right, index+1, 1);
	} else {
		right[index] = makeParent(index+1);
	}

	if (isJoined(left[index-1])){
		left[index] = joinAndReturn(left, index-1, 0);
	} else {
		left[index] = makeParent(index-1);
	}

	int r = right[index].value - index;
	int l = index - left[index].value;

	long long int result = ((long long int)value * r * l);
	return result;
}

int main(void) {
	int i;

	scanf("%d", &count);

	for (i = 1; i <= count; i++){
		scanf("%d", &sequence[i].value);
		sequence[i].index = i;
	}

	count += 2;

	sequence[count-1].value = MAXLENGTH;
	sequence[count-1].index = count-1;

	left[0] = makeParent(0);
	right[count-1] = makeParent(count-1);

	qsort(sequence, count, sizeof(seq), seqCmp);

	long long int total = 0;
	for (i = count - 2; i > 0; i--){
		total += doMagic(sequence[i].index, sequence[i].value);
	}

	printf("%lld\n", total);

	return 0;
}

