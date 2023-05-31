#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    ll d[505][505];
    memset(d, -1, sizeof(d));
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d[a][b] = (d[a][b] == -1 ? c : min(d[a][b], 1ll * c));
        d[b][a] = d[a][b];
    }
    for (int i = 0; i < n; i++) {
        d[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == -1 || d[k][j] == -1) continue;

                if (d[i][j] == -1)
                    d[i][j] = d[i][k] + d[k][j];
                else
                    d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << d[a][b] << '\n';
    }

    return 0;
}
