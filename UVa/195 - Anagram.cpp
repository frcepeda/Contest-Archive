#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
char w[100];
int wlen;

bool cmp(char a, char b){
	return tolower(a) < tolower(b) || (tolower(a) == tolower(b) && isupper(a) && islower(b));
}

int main() {
	int T;
	
	scanf("%d", &T);
	
	while (T--){
		scanf("%s", w);
		wlen = strlen(w);
		
		sort(w, w + wlen, cmp);
		
		do
			puts(w);
		while (next_permutation(w, w + wlen, cmp));
	}
}