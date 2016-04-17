#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
ll T;
string dir;
string disp;
string s;

int main(){
	while (cin >> N >> T >> dir){
		getline(cin, disp);
		getline(cin, disp);
		getline(cin, disp);

		s = "";
		for (int i = 0; i < N; i++)
			s += disp[2*i+1];
		s += s;

		int z;

		if (dir[0] == 'L')
			z = T % N;
		else
			z = N - T % N;

		getline(cin, disp);
		cout << disp << endl;
		cout << '|';

		for (int i = 0; i < N; i++)
			cout << s[i+z] << '|';

		cout << endl << disp << endl;
	}
}
