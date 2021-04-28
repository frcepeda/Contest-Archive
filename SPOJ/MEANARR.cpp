#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

struct node {
    ll x;
    int p, size;
    node *L, *R;
};

int size(node *x) {
    return x == nullptr ? 0 : x->size;
}

void update(node *x) {
    if (x == nullptr) return;
    x->size = size(x->L) + size(x->R) + 1;
}

pair<node *,node *> split(node *T, ll k) {
    if (T == nullptr) {
        return make_pair(nullptr, nullptr);
    }

    node *L, *R;

    if (T->x <= k) {
        auto res = split(T->R, k);
        L = T;
        R = res.second;
        L->R = res.first;
    } else {
        auto res = split(T->L, k);
        R = T;
        L = res.first;
        R->L = res.second;
    }

    update(L);
    update(R);

    return make_pair(L, R);
}

node *merge(node *L, node *R) {
    if (L == nullptr) return R;
    if (R == nullptr) return L;

    node *res = nullptr;

    if (L->p >= R->p) {
        res = L;
        res->R = merge(L->R, R);
    } else {
        res = R;
        res->L = merge(L, R->L);
    }

    update(res);
    
    return res;
}

node nodes[200005];
int nextNode = 0;

node *insert(node *T, ll k) {
    node *n = &nodes[nextNode++];

    n->L = n->R = nullptr;
    n->p = rand();
    n->x = k;
    n->size = 1;

    return merge(T, n);
}

int N, K;

int main() {
    scanf("%d %d", &N, &K);

    ll ans = 0, s = 0;

    node *treap = insert(nullptr, 0);

    for (int i = 0; i < N; i++){
        ll x;
        scanf("%lld", &x);

        s += x - K;

        auto LR = split(treap, s);

        ans += size(LR.first);

        treap = insert(LR.first, s);
        treap = merge(treap, LR.second);
    }

    printf("%lld\n", ans);
}
