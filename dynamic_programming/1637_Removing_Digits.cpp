
#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 5, mod = 1e9 + 7;
int n; 
int dp[mxN];

int dfs(int n) {
    if (n <= 0)
        return 0;
    if (dp[n]) return dp[n];

    int ret = INT_MAX;
    int tmp = n;
    while (tmp) {
        int digit = tmp % 10;
        tmp /= 10;
        if (digit == 0) continue;
        ret = min(ret, dfs(n - digit) + 1);
    }
    return dp[n] = ret;
}

void solve() {
    cin >> n;
    int res = dfs(n);
    cout << dp[n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
