
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 1e6 + 5, mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<vector<int>> dp(n, vector<int>(m+1));
    if (v[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    }
    else {
        dp[0][v[0]] = 1;
    }
    for (int i = 1; i < n; i++) {
        if (v[i] != 0) {
            for (int j = v[i]-1; j <= v[i]+1; j++) {
                if (j <= 0 || j > m) continue;
                dp[i][v[i]] = (dp[i][v[i]] + dp[i-1][j]) % mod;
            }
        }
        else {
            for (int k = 1; k <= m; k++) {
                for (int j = k-1; j <= k+1; j++) {
                    if (j <= 0 || j > m) continue;
                    dp[i][k] = (dp[i][k] + dp[i-1][j]) % mod;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= m; i++) {
        res = (res + dp[n-1][i]) % mod;
    }
    cout << res <<  endl;
}

 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
