#include <cstdio>

using namespace std;

const int maxn = 110;
int T;
char N[maxn];

int main(){
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        scanf("%s", N);

        for (int i = 0; N[i] != '\0'; i++)
            putchar(N[i] != '4' ? N[i] : '2');
        
        putchar(' ');

        for (int i = 0; N[i] != '\0'; i++)
            putchar(N[i] != '4' ? '0' : '2');
        
        putchar('\n');
    }
}
