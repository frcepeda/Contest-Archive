#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 110
#define LIMIT (5*60*60)

int N;
int cycle[MAXN];

int main() {
	while (true){
		int i, j;
		
		for (N = 0; scanf("%d", &cycle[N]), cycle[N]; N++);
		if (N == 0) break;
		
		for (i = *min_element(cycle, cycle + N); i <= LIMIT; i++){
			for (j = 0; j < N; j++)
				if (i % (cycle[j] * 2) >= cycle[j] - 5)
					break;
			if (j == N) break;
		}
		
		if (i <= LIMIT)
			printf("%02d:%02d:%02d\n", i / 3600, i / 60 % 60, i % 60);
		else
			printf("Signals fail to synchronise in 5 hours\n");
	}
}