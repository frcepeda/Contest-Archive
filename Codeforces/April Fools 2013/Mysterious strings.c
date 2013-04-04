#include <stdio.h>

char *presidents[] = {
	"Washington",
	"Adams",
	"Jefferson",
	"Madison",
	"Monroe",
	"Adams",
	"Jackson",
	"Van Buren",
	"Harrison",
	"Tyler",
	"Polk",
	"Taylor",
	"Fillmore",
	"Pierce",
	"Buchanan",
	"Lincoln",
	"Johnson",
	"Grant",
	"Hayes",
	"Garfield",
	"Arthur",
	"Cleveland",
	"Harrison",
	"Cleveland",
	"McKinley",
	"Roosevelt",
	"Taft",
	"Wilson",
	"Harding",
	"Coolidge",
	"Hoover",
	"Roosevelt",
	"Truman",
	"Eisenhower",
	"Kennedy",
	"Johnson",
	"Nixon",
	"Ford",
	"Carter",
	"Reagan"
};

int main(void){
	int a;
	scanf("%d", &a);
	printf("%s\n", presidents[a-1]);
	return 0;
}
