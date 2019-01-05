#include <iostream>
#include <cctype>

using namespace std;

int main(){
	int b;
	string s;
	cin >> b >> s;

	int ans = 0;
	for (char c: s)
		if (isdigit(c))
			ans = (ans + c - '0') % (b-1);

	printf("%d\n", ans);
}
