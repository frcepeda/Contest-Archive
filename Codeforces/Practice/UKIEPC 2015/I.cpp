#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

char s[10000];

char *hard = "bcdgknpt";
char *endings[3] = {"ah", "oh", "uh"};

bool ishard(char c){
	for (int i = 0; hard[i]; i++)
		if (hard[i] == c)
			return true;
	return false;
}

char start(char c){
	int r = 0;
	for (int i = 1; hard[i] != '\0'; i++)
		if (abs(hard[r] - c) > abs(hard[i] - c))
			r = i;
	return hard[r];
}

int end(char c){
	int r = 0;
	for (int i = 1; i < 3; i++)
		if (abs(endings[r][0] - c) > abs(endings[i][0] - c))
			r = i;
	return r;
}

int main(){
	int i;
	bool first = true;

	while (scanf("%s", s) != EOF){
		if (!first) putchar(' ');
		else first = false;

		int n = strlen(s);

		bool up = isupper(s[0]);
		s[0] = start(tolower(s[0]));

		for (i = 0; i < n && s[i] != '-'; i++);

		for (i++; i < n; i++)
			if (ishard(s[i]))
				s[i] = s[0];

		if (up)
			s[0] = toupper(s[0]);

		for (i = 0; i < n; i++)
			if (s[i] != '-')
				putchar(s[i]);

		if (ishard(tolower(s[n-1])))
			printf("%s", endings[end(s[n-1])]);
	}

	putchar('\n');
}
