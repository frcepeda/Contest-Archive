#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int T, N;
char s[maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        scanf("%d %s", &N, s);

        int c[2] = { 0 };
        for (int i = 0; i < N; i++)
            c[s[i] == 'A']++;
        
        printf("Case #%d: %c\n", t, abs(c[0] - c[1]) == 1 ? 'Y' : 'N');
    }
}
