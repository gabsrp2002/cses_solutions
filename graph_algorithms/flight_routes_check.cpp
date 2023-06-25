#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;


int vis[100005];

void dfs(int curr, vector<vector<int>> &nei) {
    if (vis[curr]) return;
    vis[curr] = 1;
    for (auto v : nei[curr]) {
        dfs(v, nei);
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> original_nei(n + 1);
    vector<vector<int>> transpose_nei(n + 1);
    while (m--){
        int a, b;
        cin >> a >> b;
        original_nei[a].push_back(b);
        transpose_nei[b].push_back(a);
    }

    dfs(1, original_nei);

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << '\n';
            cout << 1 << ' ' << i << '\n';
            return 0;
        }
    }

    memset(vis, 0, sizeof(vis));
    dfs(1, transpose_nei);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "NO" << '\n';
            cout << i << ' ' << 1 << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}
