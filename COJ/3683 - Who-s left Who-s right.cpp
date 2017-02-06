#include <cstdio>
#include <set>
#include <iterator>

using namespace std;

int N;

set<int> s;

int main(){
	scanf("%d", &N);

	s.insert(0);
	s.insert(1000000);

	while (N--){
		int ai;
		scanf("%d", &ai);

		auto i = s.lower_bound(ai);

		printf("%d %d\n", *i == ai ? ai : *prev(i), *i);

		s.insert(ai);
	}
}
