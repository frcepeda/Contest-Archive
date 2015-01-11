#include <cstdio>
#include <queue>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,pair<int,int>> lol;
priority_queue<lol, vector<lol>, greater<lol>> Q;
int K;

int main(){
	char str[10];

	while (scanf("%s", str), str[0] != '#'){
		int id, q;
		scanf("%d %d", &id, &q);
		Q.push(mp(q, mp(id, q)));
	}

	scanf("%d", &K);

	while (K--){
		auto x = Q.top(); Q.pop();
		printf("%d\n", x.snd.fst);
		Q.push(mp(x.fst + x.snd.snd, x.snd));
	}
}
