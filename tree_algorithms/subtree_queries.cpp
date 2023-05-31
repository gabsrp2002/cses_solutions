#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, q;
vector<int> nei[200005];
int idx[200005];
int tree_sz[200005];
ll t[200005];
ll v[200005];
int timer = 1;

void dfs(int curr, int par=-1) {
    idx[curr] = timer++;
    tree_sz[curr] = 1;
    for (auto v : nei[curr]) {
        if (v == par) continue;
        dfs(v, curr);
        tree_sz[curr] += tree_sz[v];
    }
}

void update(int pos, int val) {
    while (pos <= n) {
        t[pos] += val;
        pos += pos & -pos;
    }
}

ll sum(int i, int j) {
    ll s = 0;

    while (j > 0) {
        s += t[j];
        j -= j & -j;
    }

    while (i > 0) {
        s -= t[i];
        i -= i & -i;
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        update(idx[i], v[i]);
    } 

    while (q--) {
        int flag;
        cin >> flag;
        if (flag == 1) {
            int s;
            ll x;
            cin >> s >> x;
            update(idx[s], x - v[s]);
            v[s] = x;
        } else {
            int s;
            cin >> s;
            cout << sum(idx[s] - 1, idx[s] + tree_sz[s] - 1) << '\n';
        }
    }

    return 0;
}
