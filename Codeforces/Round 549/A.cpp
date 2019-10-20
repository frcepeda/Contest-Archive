#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k, a, b;

ll go(ll s, ll l){
    return n * k / __gcd(n*k, l);
}

int main(){
    cin >> n >> k >> a >> b;

    ll x, m = LLONG_MAX, M = LLONG_MIN;
    for (ll i = 1; i <= n; i++){
        for (auto s: vector<ll>{a, k - a}){
            for (auto t: vector<ll>{i*k + b, (i+1)*k - b}){
                ll l = t - s;
                ll x = go(s, l);
                m = min(m, x);
                M = max(M, x);
            }
        }
    }

    cout << m << ' ' << M << endl;
}
