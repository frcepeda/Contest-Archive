#include <cstdio>
#include <algorithm>

#define mp make_pair
#define fst first
#define snd second

using namespace std;

const char pat[10][10] = {
	{0,1,0,1,0},
	{1,1,1,1,1},
	{0,1,0,1,0},
	{1,1,1,1,1},
	{0,1,0,1,0}
};

char s[200][200];

typedef pair<int,int> pii;

int K;

pii t(pii x){
	return mp(x.fst * K, x.snd * K);
}

bool between1D(int a, int b, int c){
	return min(a,b) <= c && c <= max(a,b);
}

bool between(pii a, pii b, pii c){
	if (!between1D(a.fst, b.fst, c.fst))
		return false;
	if (!between1D(a.snd, b.snd, c.snd))
		return false;
	return (c.snd - a.snd) * (b.fst - c.fst) ==
	       (b.snd - c.snd) * (c.fst - a.fst);
}

bool color(pii x){
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++){
			if (!pat[i][j]) continue;

			if (i + 1 < 5 && pat[i+1][j])
				if (between(t(mp(i,j)),
				            t(mp(i+1,j)),
					    x))
					return true;

			if (j + 1 < 5 && pat[i][j+1])
				if (between(t(mp(i,j)),
				            t(mp(i,j+1)),
					    x))
					return true;

			if (i + 1 < 5 && j + 1 < 5 && pat[i+1][j+1])
				if (between(t(mp(i,j)),
				            t(mp(i+1,j+1)),
					    x) &&
				    mp(i,j) != mp(0,3) &&
				    mp(i,j) != mp(3,0))
					return true;

			if (i + 1 < 5 && j - 1 >= 0 && pat[i+1][j-1])
				if (between(t(mp(i,j)),
				            t(mp(i+1,j-1)),
					    x) &&
				    mp(i,j) != mp(0,1) &&
				    mp(i,j) != mp(3,4))
					return true;
		}
	return false;
}

int main(){
	while (scanf("%d", &K) == 1){
		for (int i = 0; i < 4*K+1; i++)
			for (int j = 0; j < 4*K+1; j++)
				s[i][j] = color(mp(i,j)) ? '*' : ' ';

		for (int i = 0; i < 4*K+1; i++){
			for (int j = 4*K; j >= 0 && s[i][j] != '*'; j--)
				s[i][j] = '\0';
			s[i][4*K+1] = '\0';
		}

		for (int i = 0; i < 4*K+1; i++)
			printf("%s\n", s[i]);
	}
}
