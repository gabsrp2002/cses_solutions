#include <bits/stdc++.h>

#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int vis[100005];
vector<int> nei[100005];
vector<int> path;

bool dfs(int curr) {
    vis[curr] = 1;
    path.push_back(curr);
    for (auto v : nei[curr]) {
        if (vis[v] == 0) {
            if (dfs(v)) return 1;
        }
        if (vis[v] == 1) {
            path.push_back(v);
            return 1;
        }
    }
    vis[curr] = 2;
    path.pop_back();

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        nei[b].push_back(a);
    }

    bool found = false;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) found = dfs(i);
        if (found) break;
    }

    if (!found) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    reverse(path.begin(), path.end());

    while (path.back() != path[0]) path.pop_back();

    cout << path.size() << '\n';
    for (auto v : path) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}
