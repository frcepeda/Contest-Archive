#include <cstdio>
#include <cmath>

using namespace std;

int n, t;

int main(){
	scanf("%d", &n);

	bool ded = false;

	while (n--){
		int k;
		char s[15];

		scanf("%d %s", &k, s);

		if (s[0] == 'E' || s[0] == 'W'){
			if (t == 0 || t == 20000){
				ded = true;
				break;
			} else continue;
		} else if (s[0] == 'N')
			k *= -1;

		t += k;

		if (t < 0 || t > 20000){
			ded = true;
			break;
		}
	}

	printf("%s\n", ded || t ? "NO" : "YES");
}
