#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
int p[100005], r[100005];

int leader(int i) {
    if (i == p[i]) return i;

    return p[i] = leader(p[i]);
}

int join(int i, int j) {
    int x = leader(i), y = leader(j);

    if (x == y) return 0;

    if (r[x] >= r[y]) {
        r[x] += r[y];
        p[y] = x;
    } else {
        r[y] += r[x];
        p[x] = y;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int components = n;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        r[i] = 1;
    }

    int a, b;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        components -= join(a, b);
    }

    cout << components - 1 << '\n';

    for (int i = 1; i <= n; i++) {
        if (join(1, i)) cout << 1 << ' ' << i << '\n';
    }

    return 0;
}
