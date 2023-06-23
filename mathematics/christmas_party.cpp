#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int pot(int base, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = (1ll * res * base) % mod;
        base = (1ll * base * base) % mod;
        e >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int fact = 1;
    int sign = 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + 1ll * sign * pot(fact, mod - 2) + mod) % mod;
        sign = -sign;
        fact = (1ll * fact * (i + 1)) % mod;
    }
    ans = (ans + 1ll * sign * pot(fact, mod - 2) + mod) % mod;
    ans = (1ll * ans * fact) % mod;
    cout << ans << '\n';

    return 0;
}
