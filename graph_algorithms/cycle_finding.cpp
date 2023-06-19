#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;
const ll INF = 1e18;

struct Edge {
    int u, v, w;
};

ll dist[2505];
int par[2505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.push_back({a, b, c});
    }

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }
    dist[0] = 0;

    int start = -1;
    for (int i = 0; i < n; i++) {
        start = -1;
        for (auto edge : edges) {
            if (dist[edge.v] > dist[edge.u] + edge.w) {
                dist[edge.v] = dist[edge.u] + edge.w;
                par[edge.v] = edge.u;
                start = edge.u;
            }
        }
    }

    if (start == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        start = par[start];
    }

    vector<int> cycle;
    int curr = start;
    while (true) {
        cycle.push_back(curr);
        curr = par[curr];
        if (curr == start) break;
    }
    reverse(cycle.begin(), cycle.end());
    cout << "YES" << '\n';
    cout << start + 1;
    for (auto item : cycle) {
        cout << ' ' << item + 1;
    }
    cout << '\n';

    return 0;
}
