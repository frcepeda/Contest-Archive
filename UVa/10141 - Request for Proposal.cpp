#include <iostream>

using namespace std;

int n, p, bc, cc;
double bp, cp;
string b;
string s;

int main() {
	for (int t = 1; cin >> n >> p, (n || p); t++){
		bc = 0;
		if (t > 1) cout << endl;
		
		getline(cin, s);
		while (n--) getline(cin, s);
		
		while (p--){
			getline(cin, s);
			cin >> cp >> cc;
			
			if (cc > bc || (cc == bc && cp < bp)){
				bp = cp;
				bc = cc;
				b = s;
			}
			
			getline(cin, s);
			while (cc--) getline(cin, s);
		}
		
		cout << "RFP #" << t << endl;
		cout << b << endl;
	}
}