#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e6 + 5, mod = 1e9 + 7;
int n; 
void solve() {
    cin >> n;
    vector<vector<int>> dp;
    dp.resize(n+1, vector<int>(n+1));
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            if (row[j] == '*') {
                dp[i+1][j+1] = 0;    
            }
            else {
                dp[i+1][j+1] = (dp[i][j+1] + dp[i+1][j]) % mod;
            }
        }
    }
    cout << dp[n][n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
