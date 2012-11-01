#include <stdio.h>
#include <strings.h>

int main(){
	char str[1000];
	while (scanf("%s", &str) != EOF){
		int i, j;
		bool isPalin = true;
		for (i = 0, j = strlen(str)-1; i < j; i++, j--){
			if (str[i] != str[j]){
				isPalin = false;
				break;
			}
		}
		printf("%s\n", isPalin ? "P" : "NP");
	}
	return 0;
}

