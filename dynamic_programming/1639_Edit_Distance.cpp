#include <iostream>
#include <vector>
using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i+1][j+1] = dp[i][j];
            }
            else {
                int cur = dp[i][j];
                cur = min(cur, dp[i][j+1]);
                cur = min(cur, dp[i+1][j]);
                dp[i+1][j+1] = cur + 1;
            }
        }
    }
    cout << dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
