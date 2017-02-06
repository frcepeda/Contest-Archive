#include <cstdio>
#include <algorithm>
#include <cctype>

using namespace std;

int N;
char s[15];

int main(){
	scanf("%d %s", &N, s);
	int t = count_if(s, s + N, [](char x){ return isupper(x); });
	printf("%d %d\n", t, N-t);
}
