#include <cstdio>
#include <string>
#include <set>
#include <map>

using namespace std;

#define BLOOD 9
#define RH 4
#define mp make_pair
#define fst first
#define snd second

string printType[BLOOD] = {
	"A",
	"AB",
	"A",
	"AB",
	"B",
	"B",
	"A",
	"B",
	"O"
};

string printRH[RH] = {
	"-",
	"+",
	"+",
	"+"
};

typedef pair<int,int> blood;

string printBlood(blood b){
	return printType[b.fst] + printRH[b.snd];
}

char B[3][10];
set<string> possible;
map<string, set<blood>> possiblePairs;
map<pair<blood,blood>, set<blood>> combineBlood;

blood mkBlood(int abl, int abr, int rhl, int rhr){
	return mp(3*abl + abr, 2*rhl + rhr);
}

int main() {
	for (int i = 0; i < BLOOD; i++)
		for (int j = 0; j < RH; j++)
			possiblePairs[printType[i] + printRH[j]].insert(mp(i,j));
			
	for (int abil = 0; abil < 3; abil++)
		for (int abir = 0; abir < 3; abir++)
			for (int abjl = 0; abjl < 3; abjl++)
				for (int abjr = 0; abjr < 3; abjr++)
					for (int rhil = 0; rhil < 2; rhil++)
						for (int rhir = 0; rhir < 2; rhir++)
							for (int rhjl = 0; rhjl < 2; rhjl++)
								for (int rhjr = 0; rhjr < 2; rhjr++){
									auto &cb = combineBlood[mp(mkBlood(abil, abir, rhil, rhir),
									                           mkBlood(abjl, abjr, rhjl, rhjr))];
									cb.insert(mkBlood(abil, abjl, rhil, rhjl));
									cb.insert(mkBlood(abil, abjl, rhil, rhjr));
									cb.insert(mkBlood(abil, abjl, rhir, rhjl));
									cb.insert(mkBlood(abil, abjl, rhir, rhjr));
									cb.insert(mkBlood(abil, abjr, rhil, rhjl));
									cb.insert(mkBlood(abil, abjr, rhil, rhjr));
									cb.insert(mkBlood(abil, abjr, rhir, rhjl));
									cb.insert(mkBlood(abil, abjr, rhir, rhjr));
									cb.insert(mkBlood(abir, abjl, rhil, rhjl));
									cb.insert(mkBlood(abir, abjl, rhil, rhjr));
									cb.insert(mkBlood(abir, abjl, rhir, rhjl));
									cb.insert(mkBlood(abir, abjl, rhir, rhjr));
									cb.insert(mkBlood(abir, abjr, rhil, rhjl));
									cb.insert(mkBlood(abir, abjr, rhil, rhjr));
									cb.insert(mkBlood(abir, abjr, rhir, rhjl));
									cb.insert(mkBlood(abir, abjr, rhir, rhjr));
								}
	
	for (int t = 1; scanf("%s %s %s", B[0], B[1], B[2]), !(B[0][0] == 'E' && B[1][0] == 'N' && B[2][0] == 'D'); t++){
		int i, j, q;
		
		possible.clear();
		
		for (q = 0; B[q][0] != '?'; q++);
		
		if (q < 2){
			auto ppos = possiblePairs[B[!q]];
			auto cpos = possiblePairs[B[2]];
			
			for (auto pblood = ppos.begin(); pblood != ppos.end(); pblood++)
			for (auto cblood = cpos.begin(); cblood != cpos.end(); cblood++)
			for (i = 0; i < BLOOD; i++)
				for (j = 0; j < RH; j++)
					if (combineBlood[mp(*pblood,mp(i,j))].find(*cblood) != combineBlood[mp(*pblood,mp(i,j))].end())
						possible.insert(printType[i] + printRH[j]);
		} else {
			auto apos = possiblePairs[B[0]];
			auto bpos = possiblePairs[B[1]];
			
			for (auto ablood = apos.begin(); ablood != apos.end(); ablood++)
			for (auto bblood = bpos.begin(); bblood != bpos.end(); bblood++){
				auto &p = combineBlood[mp(*ablood,*bblood)];
				for (auto b = p.begin(); b != p.end(); b++)
					possible.insert(printBlood(*b));
			}
		}
		
		printf("Case %d: ", t);
		for (i = 0; i < 3; i++){
			if (q != i){
				printf("%s", B[i]);
			} else {
				if (possible.size() == 0)
					printf("IMPOSSIBLE");
					
				if (possible.size() > 1)
					putchar('{');
				
				bool first = true;
				for (auto it = possible.begin(); it != possible.end(); it++){
					printf("%s%s", first ? "": ", ", it->c_str());
					first = false;
				}
					
				if (possible.size() > 1)
					putchar('}');
			}
			
			putchar(i < 2 ? ' ' : '\n');
		}
	}
}
