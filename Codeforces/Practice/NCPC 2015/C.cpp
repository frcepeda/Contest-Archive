#include <cstdio>
#include <cctype>

using namespace std;

char t[4] = "PER";

int main(){
	int ans = 0;
	char c;

	for (int i = 0; isupper(c = getchar()); i = (i+1)%3)
		ans += c != t[i];
	
	printf("%d\n", ans);
}
