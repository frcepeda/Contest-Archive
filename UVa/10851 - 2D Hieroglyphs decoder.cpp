#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[100];
char m[100];;

int main() {
	int N, L;
	int i, j;
	
	scanf("%d", &N);
	
	while (N--){
		scanf("%s", m);
		
		L = strlen(m);
		fill(str, str + 100, '\0');
		
		for (j = 0; j < 8; j++){
			scanf("%s", m);
			for (i = 1; i < L-1; i++)
				str[i-1] |= (m[i] == '\\') << j;
		}
		
		scanf("%s", m);
		
		printf("%s\n", str);
	}
}