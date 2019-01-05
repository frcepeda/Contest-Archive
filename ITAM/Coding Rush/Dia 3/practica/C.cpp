#include <stdio.h>

int main(){
	char str[10];
	int count = 0;
	while (scanf("%s", str) != EOF){
		switch (str[0]){
			case 'E':
				count++;
				break;
			case 'F':
				count--;
				break;
			case 'N':
				if (count <= 4){
					count++;
					printf("espera\n");
				} else {
					printf("no espera\n");
				}
		}
	}
	return 0;
}
