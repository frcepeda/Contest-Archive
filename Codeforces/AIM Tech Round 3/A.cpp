#include <iostream>
#include <string>

using namespace std;

int main(){
	string s;
	cin >> s;

	int i;
	for (i = 0; i < s.length() && s[i] == 'a'; i++);

	if (i < s.length()){
		for (; i < s.length() && s[i] != 'a'; i++)
			s[i]--;
	} else {
		s[i-1] = 'z';
	}

	cout << s << endl;
}
