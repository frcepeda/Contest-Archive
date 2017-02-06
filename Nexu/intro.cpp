#include <cstdio>

using namespace std;

int main(){
	int f[30];

	f[0] = 0; f[1] = 1;

	for (int i = 2; i <= 26; i++)
		f[i] = f[i-1] + f[i-2];

	printf("%d\n", f[26]);
}
