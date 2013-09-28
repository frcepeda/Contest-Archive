// 84/120 points

#include <cstdio>
#include <algorithm>
#include <utility>
#include <functional>

using namespace std;

#define MAXN 300100

int N, K;
pair<int,int> jewels[MAXN]; // value, mass
int bags[MAXN];
long long int total;

bool greaterInt(int a, int b){
	return a > b;
}

bool greaterPair(pair<int,int> a, pair<int,int> b){
	return a > b;
}

int main(){
	int i, j;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
		scanf("%d %d", &jewels[i].second, &jewels[i].first);

	for (i = 0; i < K; i++)
		scanf("%d", &bags[i]);

	sort(jewels, jewels + N, greaterPair);
	sort(bags, bags + K, greaterInt);

	for (i = j = 0; i < K && j < N; i++){
		while (jewels[j].second > bags[i]) j++;
		total += jewels[j++].first;
	}

	printf("%lld\n", total);
}
