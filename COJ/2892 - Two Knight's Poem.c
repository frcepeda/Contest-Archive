#include <stdio.h>

#define MAXL 110
#define ROWS 4
#define COLS 10
#define DIRS 8

char dr[DIRS] = {2,2,1,-1,-2,-2,1,-1};
char dc[DIRS] = {1,-1,2,2,1,-1,-2,-2};

unsigned char vis[MAXL][ROWS][COLS][ROWS][COLS];
char poem[MAXL];
unsigned char t = 1;

char *keys[2][4] = {
	{"qwertyuiop","asdfghjkl;","zxcvbnm,./","**      **"},
	{"QWERTYUIOP","ASDFGHJKL:","ZXCVBNM<>?","**      **"}
};

char dfs(unsigned char i, char ar, char ac, char br, char bc){
	int d;
	char nc;

	if (poem[i] == '\0') return 1;
	else if (vis[i][ar][ac][br][bc] == t) return 0;
	vis[i][ar][ac][br][bc] = t;

	for (d = 0; d < DIRS; d++){
		signed char ar_ = ar + dr[d];
		signed char ac_ = ac + dc[d];

		if (ar_ >= 0 &&
		    ar_ < ROWS &&
		    ac_ >= 0 &&
		    ac_ < COLS &&
		    (
		     ar_ != br ||
		     ac_ != bc
		    ) &&
		    (
		     (nc = keys[keys[0][br][bc] == '*'][ar_][ac_]) == poem[i] ||
		     nc == '*'
		    ) &&
		    dfs(i + (nc != '*'), ar_, ac_, br, bc))
			return 1;
	}

	for (d = 0; d < DIRS; d++){
		signed char br_ = br + dr[d];
		signed char bc_ = bc + dc[d];

		if (br_ >= 0 &&
		    br_ < ROWS &&
		    bc_ >= 0 &&
		    bc_ < COLS &&
		    (
		     br_ != ar ||
		     bc_ != ac
		    ) &&
		    (
		     (nc = keys[keys[0][ar][ac] == '*'][br_][bc_]) == poem[i] ||
		     nc == '*'
		    ) &&
		    dfs(i + (nc != '*'), ar, ac, br_, bc_))
			return 1;
	}

	return 0;
}

int main(void){
	for (gets(poem); poem[0] != '*'; gets(poem), t++)
		printf("%c\n", dfs(0,3,0,3,9) + '0');
	return 0;
}
