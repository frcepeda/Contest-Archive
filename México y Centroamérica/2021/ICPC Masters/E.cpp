#include <cstdio>

using namespace std;

int T;

int main() {
    scanf("%d", &T);
    long long int Ax, Ay, Bx, By, D, ans;
    
    while (T--) {
        scanf("%lld %lld %lld %lld %lld", &Ax, &Ay, &Bx, &By, &D);
        ans = 0;
        for (long long int x = -100; x <= 100; x++){
            for (long long int y = -100; y <= 100; y++) {
                long long int A, B;
                A = (Ax - x) * (Ax - x) + (Ay - y)*(Ay - y);
                B = (Bx - x) * (Bx - x) + (By - y)*(By - y);
                
                if (D*D - A - B < 0)
                    continue;
                
                if (4* A * B < (D*D - A - B)* (D*D - A - B)) {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans);
    }
}
