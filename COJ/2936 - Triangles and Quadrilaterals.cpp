#include <cstdio>

using namespace std;

int main(){
    long long N, M;
    while (scanf("%lld %lld", &N, &M) != EOF)
        printf("Triangles: %lld\nQuadrilaterals: %lld\n\n", N*(N-1)/2*M + M*(M-1)/2*N, N*(N-1)*M*(M-1)/4);
}
