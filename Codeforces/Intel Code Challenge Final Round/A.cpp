#include <iostream>
#include <algorithm>

using namespace std;

int m[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string d[] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

string a, b;

int ff(string &x){
	for (int i = 0;; i++)
		if (d[i] == x)
			return i;
	return -1;
}

bool f(){
	int ad = ff(a);
	int bd = ff(b);

	for (int i = 0; i < 11; i++)
		if (m[i] % 7 == (bd - ad + 7) % 7)
			return true;

	return false;
}

int main(){
	cin >> a >> b;
	cout << (f() ? "YES" : "NO") << endl;
}
