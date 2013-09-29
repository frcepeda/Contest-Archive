// Accepted
#include <cstdio>
#include <stack>
#include <queue>
#include <cctype>

using namespace std;

stack<int> s;
queue<int> q;
priority_queue<int, vector<int>, greater<int> > pq;

int main(void){
    int T;

    scanf("%d ", &T);

    while (T--){
        char c;
        int n, a, b;

        while ((c = getchar()) != '\n' && c != EOF){
            if (isdigit(c)){
                ungetc(c, stdin);
                scanf("%d", &n);
                s.push(n);
                q.push(n);
                pq.push(n);
            } else {
                if (c == '+'){
                    a = s.top(); s.pop();
                    b = s.top(); s.pop();
                    s.push(b+a);
                    a = q.front(); q.pop();
                    b = q.front(); q.pop();
                    q.push(b+a);
                    a = pq.top(); pq.pop();
                    b = pq.top(); pq.pop();
                    pq.push(b+a);
                } else if (c == '-') {
                    a = s.top(); s.pop();
                    b = s.top(); s.pop();
                    s.push(b-a);
                    a = q.front(); q.pop();
                    b = q.front(); q.pop();
                    q.push(b-a);
                    a = pq.top(); pq.pop();
                    b = pq.top(); pq.pop();
                    pq.push(b-a);
                } else {
                    a = s.top(); s.pop();
                    b = s.top(); s.pop();
                    s.push(b*a);
                    a = q.front(); q.pop();
                    b = q.front(); q.pop();
                    q.push(b*a);
                    a = pq.top(); pq.pop();
                    b = pq.top(); pq.pop();
                    pq.push(b*a);
                }
            }

            while (isspace(c = getchar()) && c != '\n');
            ungetc(c, stdin);
        }

        printf("%d %d %d\n", s.top(), q.front(), pq.top());
        s.pop(); q.pop(); pq.pop();
    }
}
