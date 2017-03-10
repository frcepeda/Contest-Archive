#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s[100];

int main(){
	scanf("%s", s);

	int l = 0, x = 0, b = 0, L = strlen(s);
	for (int i = 0; i <= L; i++){
		if (i == L || s[i] != '.'){
			x ^= i - l;
			l = i+1;
			b += s[i] == '#';
		}
	}

	printf("%s\n", x && b ? "Cat" : "Rabbit");
}
