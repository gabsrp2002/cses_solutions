#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, q;

int boss[200005];
int lift[20][200005];
int dist[200005];
vector<int> nei[200005];

int find_dist(int curr) {
    if (dist[curr]) return dist[curr];
    if (boss[curr] == 0) return 0;
    return dist[curr] = find_dist(boss[curr]) + 1;
}

int lca(int a, int b) {
    if (dist[a] < dist[b]) {
        swap(a, b);
    }
    int exp = 0;
    int jump = dist[a] - dist[b];
    while (jump) {
        if (jump & 1) a = lift[exp][a];
        exp++;
        jump >>= 1;
    }
    if (a == b) {
        return a;
    }
    int i = 18;
    while (boss[a] != boss[b]) {
        while (lift[i][a] == lift[i][b]) i--;
        a = lift[i][a];
        b = lift[i][b];
    }
    return boss[a];
}

void dfs(int curr, int par = -1) {
    for (auto v : nei[curr]) {
        if (v == par) continue;
        boss[v] = curr;
        dfs(v, curr);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    dfs(1);

    for (int i = 2; i <= n; i++) {
        lift[0][i] = boss[i];
    }

    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            lift[i][j] = lift[i - 1][lift[i - 1][j]];
        }
    }

    for (int i = 1; i <= n; i++) {
        find_dist(i);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
    }

    return 0;
}
