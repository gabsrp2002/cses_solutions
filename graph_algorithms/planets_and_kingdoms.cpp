#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int timer;
int tout[100005];
int vis[100005];
int ans[100005];

void dfs(int curr, int label, vector<vector<int>> &g) {
    if (vis[curr]) return;
    ans[curr] = label;
    vis[curr] = 1;
    for (auto v : g[curr]) {
        dfs(v, label, g);
    }
    vis[curr] = 2;
    tout[curr] = timer++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    vector<vector<int>> g_prime(n + 1, vector<int>());
    while (m--) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g_prime[b].push_back(a);
    }

    vector<pair<int, int>> ordered_planets;
    for (int i = 1; i <= n; i++) {
        dfs(i, -1, g);
        ordered_planets.push_back({tout[i], i});
    }
    sort(ordered_planets.begin(), ordered_planets.end(),
         greater<pair<int, int>>());

    int k = 0;
    memset(vis, 0, sizeof(vis));
    for (auto p : ordered_planets) {
        if (vis[p.second]) continue;
        k++;
        dfs(p.second, k, g_prime);
    }

    cout << k << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
        
    return 0;
}
