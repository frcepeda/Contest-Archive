#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, R, C, H, V;

const int maxr = 105;

vector<int> RR, CC;
char m[maxr][maxr];
int s[maxr][maxr];

int sum(int r1, int c1, int r2, int c2){
	return s[r2][c2] - s[r1-1][c2] - s[r2][c1-1] + s[r1-1][c1-1];
}

int main(){
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		scanf("%d %d %d %d", &R, &C, &H, &V);
		
		for (int i = 1; i <= R; i++)
			scanf("%s", m[i] + 1);

		int tot = 0;

		for (int i = 1; i <= R; i++)
			for (int j = 1; j <= C; j++){
				s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (m[i][j] == '@');
				tot += m[i][j] == '@';
			}

		RR.clear(); CC.clear();
		RR.push_back(1);
		CC.push_back(1);

		bool works = tot % ((H+1)*(V+1)) == 0;

		int chunk = tot / (H+1) / (V+1);

		if (works && tot != 0) {
			int last = 1;
			for (int i = 1; i <= R; i++)
				if (sum(last, 1, i, C) == chunk * (V+1)){
					RR.push_back(i+1);
					last = i+1;
				}

			last = 1;
			for (int j = 1; j <= C; j++)
				if (sum(1, last, R, j) == chunk * (H+1)){
					CC.push_back(j+1);
					last = j+1;
				}

			works &= RR.size() == H+2;
			works &= CC.size() == V+2;

			for (int i = 0; i+1 < RR.size(); i++)
				for (int j = 0; j+1 < CC.size(); j++)
					works &= sum(RR[i], CC[j], RR[i+1]-1, CC[j+1]-1) == chunk;
		}

		printf("Case #%d: %s\n", t, works ? "POSSIBLE" : "IMPOSSIBLE");
	}
}
