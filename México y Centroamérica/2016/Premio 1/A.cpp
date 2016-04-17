#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>

using namespace std;

char l[20];
char r[20];

bool get(char *x){
	int i;
	char t = getchar();

	if (!isalpha(t)) return false;
	ungetc(t, stdin);

	for (i = 0; t != '\n' && t != EOF; i++){
		x[i] = getchar();

		do {
			t = getchar();
		} while (isalpha(t));
	}

	x[i] = '\0';

	return true;
}

int main(){
	while (get(l)){
		get(r);
		printf("%s\n", strcmp(l,r) == 0 ? "yes" : "no");
	}
}
