#include <algorithm>
#include <vector>
#include <set>
#include <climits>

using namespace std;

typedef pair<int,int> pii;
#define fst first
#define snd second
#define mp make_pair

vector<int> ans;
set<pii> av;

class BearChairs {
set<pii>::iterator locate(int x){
	for (set<pii>::iterator i = av.begin(); i != av.end(); i++)
		if (i->snd >= x)
			return i;
}

public:
vector <int> findPositions(vector <int> atLeast, int d){
    ans.resize(atLeast.size());
    av.clear();
    
	av.insert(mp(1,INT_MAX));

	for (int i = 0; i < atLeast.size(); i++){
		set<pii>::iterator pt = this->locate(atLeast[i]);
		pii spot = *pt;
		
		av.erase(pt);

		int where = max(spot.fst, atLeast[i]);
		ans[i] = where;

		if (where - spot.fst >= d)
			av.insert(mp(spot.fst, where - d));

		if (spot.snd - where >= d)
			av.insert(mp(where + d, spot.snd));
	}

	return ans;
}
};

/*
int main(){
	auto b = BearChairs();

	vector<int> v = {1,21,11,7};
	int d = 11;

	auto a = b.findPositions(v, d);
}
*/
