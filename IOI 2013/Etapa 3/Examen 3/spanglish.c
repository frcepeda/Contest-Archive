#include <stdio.h>
#include <strings.h>

#define MAXALPHA 26
#define MAXSTO 200100

typedef struct _node{
	struct _node *children[MAXALPHA];
} node;

node storage[MAXSTO];
int nextSto;

node *newNode(void){
	return &storage[nextSto++];
}

void reverse(char *str){
	int i = 0, j = strlen(str) - 1;
	for (; i < j; i++, j--){
		char c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

node *spanish, *english;
int spanishTotal, englishTotal;
int spaLetter[MAXALPHA], engLetter[MAXALPHA];
int S, E;

void addWord(node *n, char *str, int *letters, int *total){
	if (!*str) return;

	if (!n->children[*str - 'a']){
		n->children[*str - 'a'] = newNode();
		letters[*str - 'a']++;
		(*total)++;
	}

	addWord(n->children[*str - 'a'], str + 1, letters, total);
}

int main(void){
	int i;
	char tmp[1010];

	spanish = newNode();
	english = newNode();

	scanf("%d %d", &S, &E);

	while (S--){
		scanf("%s", tmp);
		addWord(spanish, tmp, spaLetter, &spanishTotal);
	}

	while (E--){
		scanf("%s", tmp);
		reverse(tmp);
		addWord(english, tmp, engLetter, &englishTotal);
	}

	int answer = spanishTotal * englishTotal;

	for (i = 0; i < MAXALPHA; i++)
		spaLetter[i] -= spanish->children[i] != 0;

	for (i = 0; i < MAXALPHA; i++)
		engLetter[i] -= english->children[i] != 0;

	for (i = 0; i < MAXALPHA; i++)
		answer -= spaLetter[i] * engLetter[i];
	
	printf("%d\n", answer);

	return 0;
}
