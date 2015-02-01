#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char str[100];

int main(){
	while (scanf("%s", str), str[0] != '#'){
		if (next_permutation(str, str + strlen(str)))
			printf("%s\n", str);
		else
			printf("No Successor\n");
	}
}
