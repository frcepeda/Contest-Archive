#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <numeric>

using namespace std;

typedef long long ll;

constexpr ll maxnum = 1000000000;

void output(vector<ll> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size()-1) {
            cout << ' ';
        } else {
            cout << endl;
        }
    }
}

int main() {
    int T, N;

    cin >> T;

    vector<ll> two, me, init;

    for (int i = 0; i < 30; i++) {
        assert((1LL<<i) <= maxnum);
        two.push_back(1LL<<i);
    }

    for (int i = 30; me.size() < 70; i++) {
        if ((i&-i) != i) {
            me.push_back(i);
        }
    }

    init.insert(init.end(), two.begin(), two.end());
    init.insert(init.end(), me.begin(), me.end());

    while (T--) {
        cin >> N;
        assert(N == 100);
        assert(two.size() + me.size() == N);

        output(init);

        vector<ll> us = me;
        for (int i = 0; i < N; i++){
            ll x;
            cin >> x;
            us.push_back(x);
        }

        ll sum = accumulate(us.begin(), us.end(), 0LL) + accumulate(two.begin(), two.end(), 0LL);
        cerr << "Sum: " << sum << endl;
        assert(sum % 2 == 0);
        sum /= 2;

        vector<ll> ans;
        for (auto x: us) {
            if (x > sum) break;
            sum -= x;
            ans.push_back(x);
        }
        assert(sum >= 0);
        assert(sum <= maxnum);
        for (int i = 0; i < 30; i++) {
            int x = (1LL<<i);
            if (sum & x) {
                ans.push_back(x);
                sum -= x;
            }
        }
        assert(sum == 0);

        output(ans);
    }
}
