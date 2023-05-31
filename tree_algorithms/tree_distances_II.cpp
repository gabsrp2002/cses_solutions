#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
ll tree_sz[200005];
ll ans[200005];
vector<int> nei[200005];

void bottom_up_dfs(int curr, int par = -1) {
    tree_sz[curr] = 1;
    for (auto v : nei[curr]) {
        if (v == par) continue;
        bottom_up_dfs(v, curr);

        tree_sz[curr] += tree_sz[v];
        ans[curr] += ans[v] + tree_sz[v];
    }
}

void top_down_dfs(int curr, int par = -1) {
    for (auto v : nei[curr]) {
        if (v == par) continue;
        ans[v] = n - tree_sz[v] + ans[curr] - tree_sz[v];

        top_down_dfs(v, curr);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    bottom_up_dfs(1);
    top_down_dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}
