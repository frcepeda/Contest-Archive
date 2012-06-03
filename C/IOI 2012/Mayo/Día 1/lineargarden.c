#include <stdio.h>
#include <math.h>

#define MAXNUM 1000001

typedef struct {
	int min, max;
	int diff;
} state;

void updateState(state *s){
	if (s->diff > s->max)
		s->max = s->diff;
	
	if (s->diff < s->min)
		s->min = s->diff;
}

long long int square(long long int n){
	return n*n;
}

int mod;

int powersOfTwo[MAXNUM/2+1] = {1, 2};
long long int twoToThe(int power){
	if (powersOfTwo[power]){
		return powersOfTwo[power];
	} else if (power % 2 == 0){
		return powersOfTwo[power] = square(twoToThe(power/2)) % mod;
	} else {
		return powersOfTwo[power] = 2 * square(twoToThe((power-1)/2)) % mod;
	}
}

long long int computeValue(state s, int remaining){
	int diff = s.max - s.min;
	
	switch (diff){
		case 1:
			return twoToThe(ceil((float)remaining/2)) + twoToThe(floor((float)remaining/2)) - 1;
		case 2:
			if (s.diff == s.min+1){
				return twoToThe(ceil((float)remaining/2));
			} else {
				return twoToThe(floor((float)remaining/2));
			}
		default:
			return 0;
	}
}

int main(void){
	int length;
	char string[MAXNUM];
	
	scanf("%d", &length);
	scanf("%d", &mod);
	scanf("%*[ \n\t\r]%[LP]", string);
	
	int i;
	
	state last = {0,0,0};
	long long int answer = 1;
	
	for (i = 0; i < length; i++){
		state curr = last;
		
		int value = string[i] == 'L' ? 1 : -1;
		curr.diff += value;
		updateState(&curr);
		
		if (string[i] == 'P'){
			state otherBranch = last;

			int other = -value;
			otherBranch.diff += other;
			updateState(&otherBranch);

			answer += computeValue(otherBranch, length-i-1);
			answer %= mod;
		}
		
		last = curr;
	}
	
	printf("%lld\n", answer);
	
	return 0;
}


