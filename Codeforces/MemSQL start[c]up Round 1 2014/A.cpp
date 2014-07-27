#include <bits/stdc++.h>

using namespace std;

#define fst first
#define snd second
#define mp make_pair

char *pokemon[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
char test[100];

int main(){
	int N;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++)
		test[i] = getchar();

	for (int i = 0; i < 8; i++){
		if (strlen(pokemon[i]) == N){
			int j;
			for (j = 0; j < N; j++)
				if (test[j] != '.' && pokemon[i][j] != test[j])
					break;
			if (j == N)
				printf("%s\n", pokemon[i]);
		}
	}
}
