// Accepted

/* Try all sequences with some light pruning. */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string a, b;
vector<char> st, op;

bool possible() {
	string a_ = a, b_ = b;
	sort(a_.begin(), a_.end());
	sort(b_.begin(), b_.end());
	return a_ == b_;
}

void tryAll(int i, int e){
	if (e == b.length()){
		bool first = true;
		for (int x = 0; x < op.size(); x++){
			cout << (first ? "" : " ") << op[x];
			first = false;
		}
		cout << '\n';
		return;
	}
	
	if (i < a.length()){
		op.push_back('i');
		st.push_back(a[i]);
		tryAll(i+1, e);
		op.pop_back();
		st.pop_back();
	}
	
	if (!st.empty() && st.back() == b[e]){
		char tmp = st.back();
		st.pop_back();
		op.push_back('o');
		tryAll(i, e+1);
		st.push_back(tmp);
		op.pop_back();
	}
}

int main() {
	while (cin >> a >> b) {
		printf("[\n");
		if (possible())
			tryAll(0, 0);
		printf("]\n");
	}
}