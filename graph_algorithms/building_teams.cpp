#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
int color[100005];
vector<int> nei[100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (color[i]) continue;
        queue<pair<int, int>> q;
        q.push({i, 1});
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (color[curr.first] == 3 - curr.second) {
                cout << "IMPOSSIBLE" << '\n';
                return 0;
            }

            if (color[curr.first]) continue;

            color[curr.first] = curr.second;
            for (auto v : nei[curr.first]) {
                q.push({v, 3 - curr.second});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    }
    cout << '\n';

    return 0;
}
