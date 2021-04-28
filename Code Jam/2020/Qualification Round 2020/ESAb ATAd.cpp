#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 105;
int T, B, tick;
bool different[maxn], bit[maxn];

bool get(int x){
    int b;

    //fprintf(stderr, "Getting %d\n", x);
    fflush(stderr);

    printf("%d\n", x);
    fflush(stdout);
    scanf("%d", &b);

    tick++;

    return b != 0;
}

int main(){
    scanf("%d %d", &T, &B);

    for (int t = 1; t <= T; t++){
        int model[2] = {-1, -1};

        tick = 0;

        for (int i = 1; i <= B/2; i++){
            if (tick > 0 && tick % 10 == 0){
                //fprintf(stderr, "Tick indicates change\n");

                bool sameMatch = false, diffMatch = false;

                if (model[0] != -1)
                    sameMatch = bit[model[0]] == get(model[0]);
                if (model[1] != -1)
                    diffMatch = bit[model[1]] == get(model[1]);

                //fprintf(stderr, "samematch: %d, diffmatch: %d\n", (int)sameMatch, (int)diffMatch);

                bool _xor = !sameMatch;
                bool flip = sameMatch ^ diffMatch;

                if (_xor){
                    //fprintf(stderr, "XORing array!\n");
                    for (int j = 1; j <= B/2; j++)
                        bit[j] ^= true;
                }

                if (flip){
                    //fprintf(stderr, "Reversing array!\n");
                    for (int j = 1; j <= B/2; j++)
                        bit[j] ^= different[j];
                }

                fflush(stderr);

                if (tick % 2) get(1);
            }

            bool left = get(i);
            bool right = get(B-i+1);

            different[i] = left != right;
            model[different[i]] = max(model[different[i]], i);

            bit[i] = left;
        }

        //fprintf(stderr, "Got solution!\n");

        for (int i = 1; i <= B/2; i++)
            putchar(bit[i] + '0');
        for (int i = B/2; i >= 1; i--)
            putchar((bit[i]^different[i]) + '0');
        putchar('\n');
        fflush(stdout);

        //fprintf(stderr, "Reading verdict\n");

        char verdict;
        scanf(" %c", &verdict);
        //fprintf(stderr, "Verdict was: %c\n", verdict);
        if (verdict != 'Y') break;
    }
}