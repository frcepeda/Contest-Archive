// 3/11 points
#include <cstdio>
#include <queue>
#include <stack>

#define UPLOAD 1

using namespace std;

#if UPLOAD
    #define openFiles() freopen("fcount.in", "r", stdin); freopen("fcount.out", "w", stdout)
#else
    #define openFiles()
#endif

// USACO upload macros

#define MAXN 505

int N;
int a[MAXN];
priority_queue<int> curr;
queue<int> ans;
stack<int> temp;

bool candidate(int x){
    int i;

    for (i = 0; i < N; i++)
        if (i != x && a[i])
            curr.push(a[i]);

    while (!curr.empty()){
        int cow = curr.top(); curr.pop();

        if (cow > curr.size())
            return false;

        for (; cow--; curr.pop())
            temp.push(curr.top()-1);

        for (; !temp.empty(); temp.pop())
            if (temp.top())
                curr.push(temp.top());
                
    }

    return true;
}

int main(){
    int i;

    openFiles();
    scanf("%d", &N);
    N++;

    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < N; i++)
        if (candidate(i))
            ans.push(i+1);

    printf("%d\n", (int)ans.size());

    for (; !ans.empty(); ans.pop())
        printf("%d\n", ans.front());
}
