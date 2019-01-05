#include <iostream>
#include <cctype>

using namespace std;

int main(){
	int b;
	string s;
	cin >> b >> s;

	int ans = 0, acc = 0;
	for (char c: s)
		if (isdigit(c))
			acc = acc * b + c - '0';

	printf("%d\n", ans % (b-1));
}
