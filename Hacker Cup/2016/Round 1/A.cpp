#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int T, N;

int main(){
	cin >> T;

	for (int t = 1; t <= T; t++){
		int ans = 0;
		stack<int> s;
		queue<int> q;

		cin >> N;

		for (int i = 0; i < N; i++){
			int z;
			cin >> z;
			q.push(z);
		}

		while (!q.empty()){
			if (s.size() == 4){
				while (!s.empty())
					s.pop();
				continue;
			}

			if (s.empty() ||
			    (q.front() > s.top() &&
			     q.front() - s.top() <= 10)){
				s.push(q.front());
				q.pop();
			} else {
				s.push(s.top() + 10);
				ans++;
			}
		}

		ans += 4 - s.size();

		cout << "Case #" << t << ": " << ans << endl;
	}
}
