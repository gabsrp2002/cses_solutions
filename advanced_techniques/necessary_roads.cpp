#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int timer;
int lowest_circle[100005];
int tin[100005];
int vis[100005];
vector<int> nei[100005];
vector<pair<int, int>> bridges;

void dfs(int curr, int par = -1) {
    vis[curr] = 1;
    lowest_circle[curr] = tin[curr] = ++timer;
    for (auto next : nei[curr]) {
        if (next == par) continue;

        if (vis[next]) {
            lowest_circle[curr] = min(lowest_circle[curr], tin[next]);
        } else {
            dfs(next, curr);
            lowest_circle[curr] = min(lowest_circle[curr], lowest_circle[next]);
            if (lowest_circle[next] > tin[curr])
                bridges.push_back({next, curr});
        }
    }
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
        a--; b--;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }
    dfs(0);

    cout << bridges.size() << '\n';
    for (auto p : bridges) {
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    }

    return 0;
}
