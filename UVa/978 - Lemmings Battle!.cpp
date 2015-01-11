#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int N, BT, SG, SB;
multiset<int, greater<int>, allocator<int>> G, B;
vector<int> Ga, Ba;

int main(){
	bool first = true;
	int i, x;

	scanf("%d", &N);

	while (N--){
		if (!first) putchar('\n');
		first = false;

		G.clear();
		B.clear();

		scanf("%d %d %d", &BT, &SG, &SB);

		for (i = 0; i < SG; i++){
			scanf("%d", &x);
			G.insert(x);
		}

		for (i = 0; i < SB; i++){
			scanf("%d", &x);
			B.insert(x);
		}

		while (G.size() && B.size()){
			auto git = G.begin(), bit = B.begin();

			Ga.clear();
			Ba.clear();

			for (i = 0; i < BT && G.size() && B.size(); i++){
				int g = *git;
				int b = *bit;

				git = G.erase(git);
				bit = B.erase(bit);

				if (b > g)
					Ba.push_back(b - g);
				else if (b < g)
					Ga.push_back(g - b);
			}

			G.insert(Ga.begin(), Ga.end());
			B.insert(Ba.begin(), Ba.end());
		}

		auto &x = G;

		if (!G.size() && !B.size())
			printf("green and blue died\n");
		else if (G.size()){
			printf("green wins\n");
			x = G;
		} else {
			printf("blue wins\n");
			x = B;
		}

		for (auto it = x.begin(); it != x.end(); it++)
			printf("%d\n", *it);
	}
}
