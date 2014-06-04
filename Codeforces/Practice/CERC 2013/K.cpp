// Accepted
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define MAXC 200

int T, N;
bool possible[MAXC][MAXC];
bool foundCycle, buildingCycle;
string cycle;
int visited[MAXC];
string best[MAXC];

string check(int c){
	if (visited[c] == 1){
		return best[c];
	} else if (visited[c] == 2){
		foundCycle = true;
		buildingCycle = true;
		visited[c] = 3;
		return "";
	}

	visited[c] = 2;
	best[c] = "";

	for (int k = 'a'; k <= 'z' && !foundCycle; k++){
		if (!possible[c][k]) continue;

		string tmp = check(k);
		if (tmp.length() > best[c].length() || foundCycle)
			best[c] = tmp;
	}

	best[c] = ((char)c) + best[c];

	if (buildingCycle)
		cycle = ((char)c) + cycle;

	if (visited[c] == 3)
		buildingCycle = false;

	visited[c] = 1;
	return best[c];
}

int main(){
	int i, j;

	scanf("%d", &T);

	while (T--){
		string best = "";
		foundCycle = buildingCycle = false;
		cycle = "";

		scanf("%d", &N);

		for (i = 0; i < MAXC; i++)
			visited[i] = 0;

		for (i = 0; i < MAXC; i++)
			for (j = 0; j < MAXC; j++)
				possible[i][j] = true;

		while (N--){
			char tmp[10];
			scanf("%s", tmp);
			possible[tmp[0]][tmp[1]] = false;
		}

		for (i = 'a'; i <= 'z' && !foundCycle; i++){
			string tmp = check(i);
			if (tmp.length() > best.length())
				best = tmp;
			if (foundCycle)
				best = cycle;
		}

		if (foundCycle)
			N = 20;
		else
			N = (best.length() + 1) / 2;

		for (i = 0; i < N; i++){
			for (j = 0; j < N; j++)
				printf("%c", best[(i+j) % best.length()]);
			printf("\n");
		}
	}
}
