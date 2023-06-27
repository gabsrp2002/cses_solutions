#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

typedef vector<vector<int>> Matrix;

Matrix mult(Matrix &a, Matrix &b) {
    Matrix res = vector<vector<int>>(a.size(), vector<int>(b[0].size(), 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                res[i][j] = (res[i][j] + 1ll * a[i][k] * b[k][j]) % mod;
            }
        }
    }

    return res;
}

Matrix pot(Matrix base, int e) {
    Matrix res = vector<vector<int>>(base.size(), vector<int>(base.size(), 0));
    for (int i = 0; i < base.size(); i++) {
        res[i][i] = 1;
    }

    while (e) {
        if (e & 1) res = mult(res, base);
        base = mult(base, base);
        e >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Matrix adj = vector<vector<int>>(n, vector<int>(n, 0));

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a][b]++;
    }

    cout << pot(adj, k)[0][n - 1] << '\n';

    return 0;
}
