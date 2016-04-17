#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAXN 50
#define MAXC 18

bool dp[1010][MAXC][MAXC][MAXC];
int exactly[1010];

class BearFair2 {
public:
string isFair(int n, int b, vector <int> upTo, vector <int> quantity){
	fill(exactly, exactly + b + 1, 0);

	for (int i = 0; i < upTo.size(); i++){
		if (exactly[upTo[i]] == 0)
			exactly[upTo[i]] = quantity[i];
		else
			return "unfair";
	}
	
	if (exactly[b] != 0 && exactly[b] != n)
		return "unfair";
	exactly[b] = n;
	
	dp[0][0][0][0] = true;
	int r[3];
	for (int i = 1; i <= b; i++)
	for (r[0] = 0; r[0] < MAXC; r[0]++)
	for (r[1] = 0; r[1] < MAXC; r[1]++)
	for (r[2] = 0; r[2] < MAXC; r[2]++)
	if (exactly[i] == 0 || r[0] + r[1] + r[2] == exactly[i]){
		dp[i][r[0]][r[1]][r[2]] = dp[i-1][r[0]][r[1]][r[2]];
		if (r[i%3] > 0){
			r[i%3]--;
			bool t = dp[i-1][r[0]][r[1]][r[2]];
			r[i%3]++;
			dp[i][r[0]][r[1]][r[2]] |= t;
		}
	}

	return dp[b][n/3][n/3][n/3] ? "fair" : "unfair";
}
};

/*
int main(){
	auto b = BearFair2();
	cout << b.isFair(3, 5, {2,3}, {1,2});
}
//*/
