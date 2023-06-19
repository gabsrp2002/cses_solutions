#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int par[100005], sz[100005];
int num_components, max_sz;

int find_par(int i) {
    if (i == par[i]) return i;

    return par[i] = find_par(par[i]);
}

void join(int i, int j) {
    int x = find_par(i);
    int y = find_par(j);

    if (x == y) return;

    if (sz[x] < sz[y]) swap(x, y);

    sz[x] += sz[y];
    par[y] = x;
    max_sz = max(sz[x], max_sz);
    num_components--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    num_components = n;
    max_sz = 1;

    while (m--) {
        int a, b;
        cin >> a >> b;
        join(a, b);
        cout << num_components << ' ' << max_sz << '\n';
    }

    return 0;
}
