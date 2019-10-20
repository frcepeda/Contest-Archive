#include <cstdio>
#include <algorithm>

using namespace std;

int T, N, k, r;

void eight(int x){
    for (int i = 0; i < min(x, k); i++)
        putchar('0');
    for (int i = k - x; i > 0; i--)
        putchar('8');
}

int main(){
    scanf("%d", &T);

    while (T--){
        scanf("%d", &N);

        k = N/7;
        r = N%7;

        if (r == 0) {
            printf("1");
            eight(1);
        } else if (r == 1) {
            printf("1");
            eight(0);
        } else if (r == 2) {
            printf("2");
            eight(2);
        } else if (r == 3) {
            printf("2");
            eight(1);
        } else if (r == 4) {
            printf("2");
            eight(0);
        } else if (r == 5) {
            printf("6");
            eight(0);
        } else if (r == 6) {
            printf("8");
            eight(0);
        }

        putchar('\n');
    }
}
