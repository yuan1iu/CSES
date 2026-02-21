#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mxN = 1e6 + 5, mod = 1e9 + 7;
ll a, b;
vector<int> d;
ll dp[20][11][2];

ll dfs(int pos, int prev, bool lim) {
    if (pos == -1) return 1;
    if (~dp[pos][prev][lim]) return dp[pos][prev][lim];
    
    int ub = lim ? d[pos] : 9;
    long long ret = 0;
    for (int i = 0; i <= ub; i++) {
        if (i == prev) continue;
        if (i == 0 && prev == 10)
            ret += dfs(pos-1, 10, lim && i == ub);
        else
            ret += dfs(pos-1, i, lim && i == ub);
    }
    return dp[pos][prev][lim] = ret;
}

ll solve(ll num) {
    d.clear();
    while (num) {
        d.push_back(num % 10);
        num /= 10;
    }
    memset(dp, -1, sizeof(dp));
    ll ret = dfs(d.size()-1, 10, true);
    return ret;
}

void solve() {
    cin >> a >> b;
    cout << solve(b) - solve(a-1);
}

 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
