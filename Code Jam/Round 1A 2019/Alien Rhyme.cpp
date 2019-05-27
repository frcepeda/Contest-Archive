#include <iostream>
#include <algorithm>

using namespace std;

int T, N;

struct node {
    node *n[30];
    bool isend;
};

node stuff[60000];
int nextNode;

node *insert(node *x, const char *s){
    if (!x) {
        x = &stuff[nextNode++];
        x->isend = false;
        fill(x->n, x->n + 30, nullptr);
    }

    if (*s == '\0')
        x->isend = true;
    else
        x->n[*s - 'A'] = insert(x->n[*s - 'A'], s+1);

    return x;
}

pair<int,int> go(node *x){
    int acc = x->isend, joined = 0;

    for (int i = 0; i < 30; i++){
        if (!x->n[i]) continue;
        auto r = go(x->n[i]);
        acc += r.second;
        joined += r.first;
    }

    if (acc >= 2){
        joined += 2;
        acc -= 2;
    }

    return {joined, acc};
}

int main(){
    cin >> T;

    string tmp;
    for (int t = 1; t <= T; t++){
        nextNode = 0;
        cin >> N;

        node *root = NULL;

        for (int i = 0; i < N; i++){
            cin >> tmp;
            reverse(tmp.begin(), tmp.end());
            root = insert(root, tmp.c_str());
        }

        int ans = 0;
        for (int i = 0; i < 30; i++)
            if (root->n[i])
                ans += go(root->n[i]).first;

        cout << "Case #" << t << ": " << ans << endl;
    }
}
