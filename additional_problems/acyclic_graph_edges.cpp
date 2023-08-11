#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

void dfs(int curr, vector<int> &vis, vector<vector<int>> &nei, vector<pair<int, int>> &ordered) {

    vis[curr] = 1;
    for (auto v : nei[curr]) {
        if (vis[v]) continue;
        ordered.push_back({curr, v});
    }
    for (auto v : nei[curr]) {
        if (vis[v]) continue;
        dfs(v, vis, nei, ordered);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> nei(n + 1, vector<int>());
    vector<int> vis(n + 1, 0);
    vector<pair<int, int>> ordered;
    while (m--) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i])
        dfs(i, vis, nei, ordered);
    }

    for (auto p : ordered) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
