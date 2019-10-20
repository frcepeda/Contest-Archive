#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

ll a, b, c, ans;
vector<pair<ll,int>> v;

ll f(ll k){
    return (a+k)*(b+k)/__gcd(a+k, b+k);
}

void go(int i, ll acc){
    if (i == v.size()){
        ll k = (acc - a % acc)%acc;
        ll fk = f(k);
        ll fans = f(ans);
        if (fk < fans || (fk == fans && k < ans))
            ans = k;
        return;
    }

    for (int j = 0; j <= v[i].second; j++){
        go(i+1, acc);
        acc *= v[i].first;
    }
}

int main(){
    cin >> a >> b;

    if (a == b){
        cout << 0 << endl;
        return 0;
    }

    if (b < a) swap(a, b);

    c = b - a;

    for (ll x = 2; x*x <= c; x++){
        if (c % x) continue;
        int cnt;
        for (cnt = 0; c % x == 0; cnt++)
            c /= x;
        v.push_back(make_pair(x, cnt));
    }
    if (c != 1) v.push_back(make_pair(c, 1));

    go(0, 1);

    cout << ans << endl;
}
