// Accepted
// For each coordinate, take the coordinates relative to the top left corner of
// the local diamond. The letter is 'a' + the manhattan distance to the center
// mod 'z' - 'a' + 1, or '.' if it's too far away.

#include <cstdio>
#include <cmath>

using namespace std;

int N;
int row0, row1, col0, col1;

char tile(int r, int c){
	int d = abs(r - (N-1)) + abs(c - (N-1));
	return d >= N ? '.' : 'a' + d % ('z' - 'a' + 1);
}

int main() {
	for (int t = 1; scanf("%d %d %d %d %d", &N, &row0, &col0, &row1, &col1) != EOF && N; t++){
		printf("Case %d:\n", t);
		for (int i = row0; i <= row1; i++){
			for (int j = col0; j <= col1; j++)
				putchar(tile(i % (2*N-1), j % (2*N-1)));
			putchar('\n');
		}
	}
}
