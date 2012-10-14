#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXN 100001

typedef struct {
	int next;
	char c;
} node;

node string[MAXN];
int nextString = 1;

int start = 1, end = 1, curr = 0;

int main(void){
	bool done = false, before = false, atend = true;
	char c;

	while (!done && (c = getchar())){
		if (isalpha(c) || c == ' '){
			if (before){
				before = false;
				string[nextString].c = c;
				start = nextString;
				string[nextString].next = curr;
			} else {
				string[nextString].c = c;
				string[nextString].next = string[curr].next;
				string[curr].next = nextString;
			}
			if (atend){
				end = curr = nextString++;
			} else {
				curr = nextString++;
			}
		} else {
			switch (c){
				case '[':
					curr = start;
					before = true;
					atend = false;
					break;
				case ']':
					curr = end;
					atend = true;
					before = false;
					break;
				default:
					done = true;
			}
		}
	}

	for (curr = start; curr != 0; curr = string[curr].next){
		putchar(string[curr].c);
	}
	putchar('\n');

	return 0;
}

