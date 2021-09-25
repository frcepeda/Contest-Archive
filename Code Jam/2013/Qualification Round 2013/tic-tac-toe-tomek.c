#include <stdio.h>

char *result[] = {
	"X won",
	"O won",
	"Draw",
	"Game has not completed"
};

char board[4][4];
char *player = "XO";
int T;

int main(void){
	int t;

	scanf("%d", &T);

	for (t = 1; t <= T; t++){
		int i, j, k, ans = -1;

		for (i = 0; i < 4; i++)
			for (j = 0; j < 4; j++)
				do
					board[i][j] = getchar();
				while (board[i][j] != 'X' &&
				       board[i][j] != 'T' &&
				       board[i][j] != 'O' &&
				       board[i][j] != '.');

		for (k = 0; k <= 1; k++){
			for (i = 0; i < 4; i++){
				for (j = 0; j < 4; j++)
					if (board[i][j] != player[k] && board[i][j] != 'T') break;
				if (j == 4)
					ans = k;
			}

			for (j = 0; j < 4; j++){
				for (i = 0; i < 4; i++)
					if (board[i][j] != player[k] && board[i][j] != 'T') break;
				if (i == 4)
					ans = k;
			}

#define winning(b,k) (b == player[k] || b == 'T')
			
			if (winning(board[0][0],k) && winning(board[1][1],k) && winning(board[2][2],k) && winning(board[3][3],k))
				ans = k;
			if (winning(board[0][3],k) && winning(board[1][2],k) && winning(board[2][1],k) && winning(board[3][0],k))
				ans = k;
		}

		if (ans == -1)
			for (i = 0; i < 4; i++)
				for (j = 0; j < 4; j++)
					if (board[i][j] == '.')
						ans = 3; // not completed

		if (ans == -1)
			ans = 2; // draw

		printf("Case #%d: %s\n", t, result[ans]);
	}

	return 0;
}
