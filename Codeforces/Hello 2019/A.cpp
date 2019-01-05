// Accepted
#include <iostream>

using namespace std;

bool works(string a, string b){
	return a[0] == b[0] || a[1] == b[1];
}

int main(){
	string s, t;

	cin >> t;

	for (int i = 0; i < 5; i++){
		cin >> s;
		if (works(s, t)){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}
