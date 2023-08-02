#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

#define MAXN 1005

int partial_rec[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char t;
            cin >> t;
            partial_rec[i][j] = partial_rec[i - 1][j] + partial_rec[i][j - 1] -
                                partial_rec[i - 1][j - 1] + (t == '*');
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << partial_rec[x2][y2] - partial_rec[x2][y1 - 1] -
                    partial_rec[x1 - 1][y2] + partial_rec[x1 - 1][y1 - 1]
             << '\n';
    }

    return 0;
}
