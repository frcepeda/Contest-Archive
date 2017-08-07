#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int T;

int main(){
	cin >> T;

	while (T--){
		string f, l, best;

		cin >> f >> l;

		for (int i = 1; i <= f.size(); i++)
			for (int j = 1; j <= l.size(); j++){
				string alias = f.substr(0, i) + l.substr(0, j);

				if (best.empty() || alias < best)
					best = alias;
			}

		cout << best << endl;
	}
}
