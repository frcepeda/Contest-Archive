#include <cstdio>
#include <optional>

using namespace std;

int T, N, M, A, B;

optional<pair<int,int>> solve() {
    int d = N + M - 2;
    auto ans = make_pair(A-d, B-d);
    if (ans.first <= 0 || ans.second <= 0) {
        return nullopt;
    }
    return ans;
}

int main() {
    scanf("%d", &T);

    for (int t = 1; t <= T; t++){
        printf("Case #%d: ", t);

        scanf("%d %d %d %d", &N, &M, &A, &B);

        auto ans = solve();

        if (!ans) {
            printf("Impossible\n");
        } else {
            printf("Possible\n");

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (i == 0 && j == 0) {
                        printf("%d", ans->first);
                    } else if (i == 0 && j == M-1) {
                        printf("%d", ans->second);
                    } else {
                        printf("1");
                    }
                    putchar(j < M-1 ? ' ' : '\n');
                }
            }
        }
    }
}
