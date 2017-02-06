#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
long long dp[10010][2010];
long long c[10010];

int D = 1000;

int main() {
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
        cin >> c[i];
    
    for (int j = -k; j <= k; j++)
        dp[n][j+D] = j >= 0 ? 0 : (1LL<<60);
    
    for (int i = n-1; i >= 0; i--){
        for (int j = -k; j <= k; j++){
            if (i + j >= n){
                dp[i][j+D] = 0;
            } else {
                dp[i][j+D] = min(c[i] + dp[i+1][k+D], -j >= k ? (1LL<<60) : dp[i+1][j-1+D]);
            }
        }
    }
    
    cout << dp[0][D] << endl;
}

