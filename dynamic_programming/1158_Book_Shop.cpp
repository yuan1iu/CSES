#include <bits/stdc++.h>
using namespace std;
const int mxN = 100005, mod = 1e9 + 7;
int n, x; 
void solve() {
    cin >> n >> x;
    vector<int> price(n), page(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> page[i];
    vector<int> dp(x+1);
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
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
