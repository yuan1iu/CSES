#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6, mod = 1e9+7;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    vector<int> dp(x+1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] + dp[i-coins[j]]) % mod;
            }
        }
    }
    cout << dp[x] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
