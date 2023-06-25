#include <bits/stdc++.h>

#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int vis[100005];
int route_len[100005];
int pi[100005];

void dfs(int curr, vector<vector<int>> &nei) {
    if (vis[curr]) return;
    vis[curr] = 1;
    for (auto v : nei[curr]) {
        dfs(v, nei);
        if (route_len[v] > route_len[curr]) {
            pi[curr] = v;
            route_len[curr] = route_len[v];
        }
    }
    if (route_len[curr] == 0 && curr != 1) return;

    route_len[curr]++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> nei(n + 1);
    while (m--) {
        int a, b;
        cin >> a >> b;
        nei[b].push_back(a);
    }

    dfs(n, nei);

    if (route_len[n] == 0) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << route_len[n] << '\n';
    vector<int> route;
    while (n != 0) {
        route.push_back(n);
        n = pi[n];
    }
    while (!route.empty()) {
        cout << route.back() << ' ';
        route.pop_back();
    }
    cout << '\n';

    return 0;
}
