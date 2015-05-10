#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstring>

#define fst first
#define snd second
#define mp make_pair

using namespace std;

char out[] = "!@#$%&abcdefghijklmnopqrstuvwxyz";
int N, printed;

pair<long long, int> get(){
	int i;
	long long acc = 0;

	for (i = 0; i < 5; i++){
		int x;
		if (scanf("%d", &x) == EOF) break;
		acc = (acc << 8) | x;
	}

	return mp(acc << (8 * (5-i)), (8*i+4)/5);
}

int main(){
	while (true){
		pair<long long, int> r = get();

		if (!r.snd) break;

		for (int i = 0; i < r.snd; i++){
			putchar(out[(r.fst >> (5*(7-i))) & ((1<<5)-1)]);
			if (++printed == 80){
				putchar('\n');
				printed = 0;
			}
		}
	}

	if (printed)
		putchar('\n');
}
