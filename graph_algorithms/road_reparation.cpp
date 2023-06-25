#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

struct Edge {
    int u, v, w;
};

int par[100005], sz[100005];
int total_components;

int find_par(int i) {
    if (i == par[i]) return i;

    return par[i] = find_par(par[i]);
}

int join(int i, int j) {
    int x = find_par(i);
    int y = find_par(j);

    if (x == y) return 0;

    if (sz[x] < sz[y]) swap(x, y);

    sz[x] += sz[y];
    par[y] = x;
    total_components--;
    return 1;
}

bool compare_edges(Edge a, Edge b) {
    return a.w > b.w;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;

    total_components = n;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), compare_edges);

    ll ans = 0;
    while (!edges.empty()) {
        Edge edge = edges.back();
        edges.pop_back();

        if (join(edge.u, edge.v)) ans += edge.w;
    }

    if (total_components != 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    cout << ans << '\n';

    return 0;
}
