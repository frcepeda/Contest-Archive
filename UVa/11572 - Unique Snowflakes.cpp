#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;

unordered_set<int> in;
int N, T;
vector<int> a;

int main(){
	scanf("%d", &T);

	while (T--){
		int i, j, ans = 0;

		in.clear();
		a.clear();

		scanf("%d", &N);

		for (i = 0; i < N; i++){
			scanf("%d", &j);
			a.push_back(j);
		}

		for (i = j = 0; j < N; j++){
			if (in.find(a[j]) != in.end()){
				for (; a[i] != a[j]; i++)
					in.erase(a[i]);
				i++;
			}

			in.insert(a[j]);
			ans = max(ans, j - i + 1);
		}

		printf("%d\n", ans);
	}
}
