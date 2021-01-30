#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

int N;

int main(){
    int ans = 0;
    char str[110];

    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        scanf("%s", str);
        for (int j = strlen(str)-1; j >= 0; j--){
            ans += !!isalpha(str[j]);
        }
    }

    printf("%d\n", ans);
}
