#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string s;
	int n, k;

	cin >> n >> k >> s;
	
	vector<bool> v(n);
	stack<int> st;

	for (int i = 0; i < s.size() && k; i++){
		if (s[i] == '(')
			st.push(i);
		else {
			v[i] = v[st.top()] = true;
			st.pop();
			k -= 2;
		}
	}

	for (int i = 0; i < s.size(); i++)
		if (v[i])
			cout << s[i];
	cout << endl;
}
