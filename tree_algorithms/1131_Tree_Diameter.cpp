#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, d[mxN], ans;
vector<int> adj[mxN];

void dfs(int u, int p) {
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        ans = max(ans, d[u] + d[v]);
        d[u] = max(d[u], d[v]);
    }
    d[u] += 1;
}
 
void solve() {
    cin >> n;
    int u, v;
    while (--n) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
