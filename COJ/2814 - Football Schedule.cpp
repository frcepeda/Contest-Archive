// Accepted
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

#define MAXT 210
#define MAXF 10

int N, F, T;
string teams[MAXT], fields[MAXT];

int main(void){
	int s;
	string str;

	getline(cin, str);
	sscanf(str.c_str(), "%d", &N);

	for (s = 1; s <= N; s++){
		int i, j, f = 0;

		getline(cin, str);
		sscanf(str.c_str(), "%d %d", &T, &F);

		for (i = 0; i < T; i++)
			getline(cin, teams[i]);

		sort(teams, teams + T);

		for (i = 0; i < T; i++)
			teams[i+T] = teams[i];

		for (i = 0; i < F; i++)
			getline(cin, fields[i]);

		cout << "Season " << s << endl;
		for (i = T; i > 0; i--){
			for (j = 0; j < T/2; j++, f++)
				cout << teams[i+j] << " vs " << teams[i+T-j-2] << " " << fields[f%F] << endl;
			f++;
			cout << "Rest: " << teams[i+T-1] << endl;
		}
	}
}
