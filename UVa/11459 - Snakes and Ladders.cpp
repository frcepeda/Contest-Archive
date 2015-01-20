#include <cstdio>
#include <algorithm>

#define MAXP 1000100
#define MAXB 110

using namespace std;

int board[MAXB];
int players[MAXP];
int a, b, c, T;

int main() {
	scanf("%d", &T);
	
	while (T--){
		scanf("%d %d %d", &a, &b, &c);
		
		fill(board, board + MAXB, 0);
		fill(players, players + a, 1);
		
		while (b--){
			int x, y;
			scanf("%d %d", &x, &y);
			board[x] = y;
		}
		
		for (int i = 0; c--; i = (i+1) % a){
			int x;
			scanf("%d", &x);
			players[i] = min(players[i] + x, 100);
			if (board[players[i]]) players[i] = board[players[i]];
			if (players[i] == 100) break;
		}
		
		while (c-- > 0) scanf("%*d");
		
		for (int i = 0; i < a; i++)
			printf("Position of player %d is %d.\n", i+1, players[i]);
	}
}