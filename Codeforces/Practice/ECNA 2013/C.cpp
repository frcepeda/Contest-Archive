#include <cstdio>
#include <cctype>

using namespace std;

char key[5][6];
int row[26], col[26];
char nchar = 25;

char next(char c){
	nchar = (nchar + 1) % 26;
	while (nchar + 'A' == 'J' || nchar + 'A' == c) nchar = (nchar + 1) % 26;
	return nchar + 'A';
}

void encrypt(char a, char b){
	char x, y;
	if (row[a-'A'] == row[b-'A']){
		x = key[row[a-'A']][(col[a-'A']+1) % 5];
		y = key[row[b-'A']][(col[b-'A']+1) % 5];
	} else if (col[a-'A'] == col[b-'A']) {
		x = key[(row[a-'A']+1) % 5][col[a-'A']];
		y = key[(row[b-'A']+1) % 5][col[b-'A']];
	} else {
		x = key[row[a-'A']][col[b-'A']];
		y = key[row[b-'A']][col[a-'A']];
	}
	printf("%c%c", x, y);
}

int main(){
	int t, T;

	scanf("%d\n", &T);

	for (t = 1; t <= T; t++){
		int i = 0, j;
		char c, n;
		bool used[26] = {0};
		nchar = 25;

		printf("Case %d: ", t);

		while ((c = toupper(getchar())) != '\n'){
			if (!isupper(c)) continue;
			if (!used[c-'A']){
				if (c == 'I' || c == 'J'){
					used['I'-'A'] = true;
					used['J'-'A'] = true;
				}

				used[c-'A'] = true;
				key[i/5][i%5] = c;
				i++;
			}
		}

		for (j = 0; j < 26; j++)
			if (!used[j]){
				if (j + 'A' == 'I')
					used['J'-'A'] = true;
				key[i/5][i%5] = j + 'A';
				i++;
			}

		for (i = 0; i < 5; i++)
			for (j = 0; j < 5; j++){
				if (key[i][j] == 'J')
					key[i][j] = 'I';
				row[key[i][j]-'A'] = i;
				col[key[i][j]-'A'] = j;
			}

		while ((c = toupper(getchar())) != '\n'){
			if (!isupper(c)) continue;

			do
				n = toupper(getchar());
			while (!isupper(n) && n != '\n');

			if (c == n || n == '\n') {
				ungetc(n, stdin);
				n = next(c);
			}

			//fprintf(stderr, "%c%c", c, n);
			encrypt(c,n);
		}

		//fprintf(stderr, "\n");
		printf("\n");
	}
}
