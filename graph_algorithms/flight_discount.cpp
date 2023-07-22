#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

vector<long long> min_costs(int from,
                            const vector<vector<pair<int, int>>> &neighbors) {
    vector<long long> min_costs(neighbors.size(), INT64_MAX);
    min_costs[from] = 0;
    std::priority_queue<pair<long long, int>> frontier;
    frontier.push({0, from});
    while (!frontier.empty()) {
        pair<long long, int> curr_state = frontier.top();
        frontier.pop();
        int curr = curr_state.second;
        if (-curr_state.first != min_costs[curr]) continue;

        for (auto [n, nc] : neighbors[curr]) {
            long long new_cost = min_costs[curr] + nc;
            if (new_cost < min_costs[n]) {
                min_costs[n] = new_cost;
                frontier.push({-new_cost, n});
            }
        }
    }
    return min_costs;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> nei(n + 1, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> nei_t(n + 1, vector<pair<int, int>>());
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        nei[a].push_back({b, c});
        nei_t[b].push_back({a, c});
    }

    vector<ll> costs1 = min_costs(1, nei);
    vector<ll> costsn = min_costs(n, nei_t);

    ll total_min = INT64_MAX;
    for (int i = 1; i <= n; i++) {
        if (costs1[i] == INT64_MAX) continue;
        for (auto [v, cost] : nei[i]) {
            if (costsn[v] == INT64_MAX) continue;

            total_min = min(total_min, costs1[i] + costsn[v] + cost / 2);
        }
    }

    cout << total_min << '\n';

    return 0;
}
