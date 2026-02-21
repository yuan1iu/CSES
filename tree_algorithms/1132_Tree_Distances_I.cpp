#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5;
int n, d[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs(int u, int p) {
    d[u] = 0;
    for (int v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        d[u] = max(d[u], d[v] + 1);
    }
}

// pd: parent distance
void dfs2(int u, int p, int pd) {
    ans[u] = max(d[u], pd);
    vector<pair<int, int>> cand;
    cand.push_back({pd, -1});
    for (int v: adj[u]) {
        if (v == p) continue;
        cand.push_back({d[v] + 1, v});
    }
    sort(cand.begin(), cand.end(), greater<>());

    for (int v: adj[u]) {
        if (v == p) continue;
        if (v == cand[0].second)
            dfs2(v, u, cand[1].first + 1);
        else
            dfs2(v, u, cand[0].first + 1);
    }
}

void solve() {
    cin >> n;
    int u, v;
    for (int i = 0; i < n-1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
