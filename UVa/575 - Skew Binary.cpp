#include <cstdio>
#include <cctype>

using namespace std;

int main(){
	while (true){
		int n = 0, a = 0;
		char c;
		
		while (!isdigit(c = getchar()));
		ungetc(c, stdin);
		
		while (isdigit(c = getchar())){
			n = 2 * n + a + c - '0';
			a += c - '0';
		}
		
		if (n) printf("%d\n", n);
		else break;
	}
}
