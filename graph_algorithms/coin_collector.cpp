#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

#define MAXN 100005

int k[MAXN];
ll final_k[MAXN];
ll dp[MAXN];
int label[MAXN];
int vis[MAXN];
vector<int> adj[MAXN];
vector<int> adj_t[MAXN];
vector<int> big_adj[MAXN];
vector<int> order;

void dfs1(int curr) {
    if (vis[curr]) return;
    vis[curr] = 1;
    for (auto v : adj[curr]) {
        dfs1(v);
    }
    order.push_back(curr);
}

void dfs2(int curr, int l) {
    if (label[curr]) return;
    label[curr] = l;
    for (auto v : adj_t[curr]) {
        dfs2(v, l);
    }
}

ll dfs3(int curr) {
    if (dp[curr]) return dp[curr];
    for (auto v : big_adj[curr]) {
        dfs3(v);
        dp[curr] = max(dp[curr], dp[v]);
    }
    dp[curr] += final_k[curr];

    return dp[curr];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj_t[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        dfs1(i);
    }
    reverse(order.begin(), order.end());
    int curr_label = 0;
    for (auto v : order) {
        if (!label[v]) dfs2(v, ++curr_label);
    }

    for (int i = 1; i <= n; i++) {
        final_k[label[i]] += k[i];
    }

    for (int i = 1; i <= n; i++) {
        for (auto v : adj[i]) {
            if (label[i] == label[v]) continue;
            big_adj[label[i]].push_back(label[v]);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(dfs3(i), ans);
    }

    cout << ans << '\n';

    return 0;
}
