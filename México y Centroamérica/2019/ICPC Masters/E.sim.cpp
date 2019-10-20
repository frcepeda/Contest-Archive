#include <cstdio>
#include <bitset>

using namespace std;

const int maxn = 100000;
int N;
int SG[maxn];

int mex(const bitset<maxn> &b){
    for (int i = 0;; i++)
        if (!b[i])
            return i;
}

int main(){
    SG[0] = 0;

    bitset<maxn> seen;
    for (int i = 1; i < maxn; i++){
        seen.reset();

        // one
        for (int j = 0; j <= i-1; j++)
            seen.set(SG[j] ^ SG[i-j-1]);

        // two
        for (int j = 0; j <= i-2; j++)
            seen.set(SG[j] ^ SG[i-j-2]);
        
        SG[i] = mex(seen);
    }

    for (int i = 0; i < maxn; i++){
        if (SG[i]) continue;

        string two;

        for (int j = 7; j >= 0; j--)
            two += (SG[i] & (1<<j)) ? '1' : '0';

        printf("%3d: %s\n", i, two.c_str());
    }
}
