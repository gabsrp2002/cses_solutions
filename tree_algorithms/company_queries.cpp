#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, q;

int boss[200005];
int lift[20][200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 2; i <= n; i++) {
        cin >> boss[i];
        lift[0][i] = boss[i];
    }

    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= n; j++) {
            lift[i][j] = lift[i - 1][lift[i - 1][j]]; 
        }
    }

    while (q--) {
        int x, k;
        cin >> x >> k;
        int exp = 0;
        while (k) {
            if (k & 1) x = lift[exp][x];
            exp++;
            k >>= 1;
        }
        cout << (x ? x : -1) << '\n';
    }

    return 0;
}
