#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int T;
ll N;

int main(){
	cin >> T;

	while (T--){
		cin >> N;

		cout << ((N+1)*(N+2) + 5)/6 << endl;
	}
}
