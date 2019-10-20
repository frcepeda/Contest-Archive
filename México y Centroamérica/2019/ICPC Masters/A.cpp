#include <cstdio>
#include <algorithm>
#include <bitset>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;

const int maxs = 1000100;
char S[maxs];
int T, N, K;

struct mat {
    ll m[26][26];
};

mat times(mat a, mat b){
    mat c;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            c.m[i][j] = 0;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            for (int k = 0; k < 26; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % mod;
    
    return c;
}

mat matexp(mat m, ll e){
    mat r;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            r.m[i][j] = i == j;

    for (; e; e /= 2){
        if (e % 2)
            r = times(r, m);
        m = times(m, m);
    }

    return r;
}

int main(){
    scanf("%d", &T);

    while (T--){
        ll v[26] = {0};

        scanf("%s %d %d", S, &K, &N);
        for (int i = 0; S[i] != '\0'; i++)
            v[S[i]-'a']++;

        mat m;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                m.m[i][j] = 0;

        bitset<26> used;
        while (K--){
            char c;
            scanf(" %c %s", &c, S);

            used[c-'a'] = 1;

            for (int i = 0; S[i] != '\0'; i++)
                m.m[S[i]-'a'][c-'a']++;
        }

        for (int i = 0; i < 26; i++)
            if (!used[i])
                m.m[i][i] = 1;

        auto tot = matexp(m, N);

        ll ans = 0;
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                ans = (ans + tot.m[i][j] * v[j]) % mod;

        printf("%lld\n", ans);
    }
}
