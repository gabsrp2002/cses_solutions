#include <bits/stdc++.h>

#include <queue>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long
const ll INF = 1e18 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    ll d[100005];
    cin >> n >> m;
    vector<vector<pair<int, int>>> nei(n);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
        q;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        nei[a].push_back({b, c});
    }

    for (int i = 0; i < n; i++) {
        d[i] = INF;
    }
    d[0] = 0;
    q.push({d[0], 0});

    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (p.first > d[p.second]) continue;
        for (auto next : nei[p.second]) {
            if (d[next.first] > p.first + next.second) {
                d[next.first] = p.first + next.second;
                q.push({d[next.first], next.first});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';

    return 0;
}
