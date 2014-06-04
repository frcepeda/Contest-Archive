// Accepted
#include <algorithm>
#include <cstdio>

using namespace std;

int len[4];

int main(void){
	int i, t;

	scanf("%d", &t);

	while (t--){
		int s = 0;

		for (i = 0; i < 4; i++){
			scanf("%d", &len[i]);
			s += len[i];
		}

		sort(len, len+4);

		if (len[0] == len[1] && len[2] == len[3]){
			if (len[1] == len[2])
				printf("square\n");
			else
				printf("rectangle\n");
		} else {
			bool works = true;
			for (i = 0; i < 4; i++)
				works &= s - len[i] > len[i];

			if (works)
				printf("quadrangle\n");
			else
				printf("banana\n");
		}
	}
}
