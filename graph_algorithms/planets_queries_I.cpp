#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> up(31, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> up[0][i];
    }
    for (int i = 1; i < 31; i++) {
        for (int j = 1; j <= n; j++) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int i = 0; i < 31; i++) {
            if (k & (1 << i)) x = up[i][x];
        }
        cout << x << '\n';
    }

    return 0;
}
