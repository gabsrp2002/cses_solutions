#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long
const ll INF = 1e18 + 10;

struct edge {
    int a, b, x;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<edge> edges(0);
    ll d[2505];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        d[i] = -INF;
    }
    for (int i = 0; i < m; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        a--;
        b--;
        edges.push_back({a, b, x});
    }
    d[0] = 0;
    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            if (d[e.a] != -INF) d[e.b] = max(d[e.a] + e.x, d[e.b]);
        }
    }

    for (int i = 1; i < n; i++) {
        for (auto e : edges) {
            if (d[e.b] != -INF && d[e.a] + e.x > d[e.b]) {
                d[e.b] = INF;
            }
        }
    }

    cout << (d[n - 1] == INF ? -1 : d[n - 1]) << '\n';

    return 0;
}
