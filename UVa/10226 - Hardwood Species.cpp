// Submission Error
#include <cstdio>
#include <map>
#include <cstring>
#include <cctype>

using namespace std;

struct cCmp {
	bool operator () (const char *a, const char *b){
		return strcmp(a,b) < 0;
	}
};

map<char *, int, cCmp> count;
char strs[10000][31];


bool readString(char *s){
	size_t lim = 31;
	getline(&s, &lim, stdin);
	
	char *t;
	for (t = s; *t; t++);
	while (s != t && !isalpha(*(t-1)))
		*--t = '\0';
		
	return s != t;
}

int main() {
	int T, tot, spc;
	map<char *, int>::iterator it;
	
	scanf("%d", &T);
	getchar(); getchar();
	
	while (T--){
		count.clear();
		
		for (tot = spc = 0; readString(strs[spc]); tot++){
			it = count.find(strs[spc]);
			count[strs[spc]]++;
			spc += it == count.end();
		}
		getchar();
			
		for (it = count.begin(); it != count.end(); it++)
			printf("%s %.4lf\n", it->first, (double)it->second/tot*100);
			
		if (T)
			putchar('\n');
	}
}
