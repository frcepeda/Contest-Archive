#include <cstdio>

using namespace std;

int T, N, P;

int main(){
    scanf("%d", &T);
    
    while (T--){
        scanf("%d %d", &N, &P);
        bool win = !!N;
        printf("%d\n", win ^ P);
    }
}
