#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

#define MAXN 200010

int ad[MAXN];
int numbers[MAXN];
set< pair<int,short> > tmp;

int matches[MAXN];
int matchCount;

int N, M;

int main(void){
	int i, j;

	scanf("%d %d", &N, &M);

	if (N > MAXN){
		printf("0\n\n");
		return 0;
	}

	for (i = 0; i < N; i++)
		scanf("%d", &ad[i]);

	for (i = 0; i < M; i++)
		scanf("%d", &numbers[i]);

	for (i = 0; i < N; i++)
		tmp.insert(make_pair(numbers[i],i));

	for (i = N-1; i <= M; i++){
		set< pair<int,short> >::iterator it;

		if (i >= N){
			tmp.erase(make_pair(numbers[i-N],i-N));
			tmp.insert(make_pair(numbers[i],i));
		}

		bool works = true;
		for (j = 0, it = tmp.begin(); it != tmp.end(); it++, j++){
			if (ad[j] + i - N != it->second){
				works = false;
				break;
			}
		}

		if (works)
			matches[matchCount++] = i - N + 2;
	}


	printf("%d\n", matchCount);

	for (i = 0; i < matchCount; i++)
		printf("%d%s", matches[i], i != matchCount-1 ? " " : "");
	printf("\n");

	return 0;
}

