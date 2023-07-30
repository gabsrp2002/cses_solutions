#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int pot(int base, int exp) {
    int ans = 1;
    while (exp) {
        if (exp & 1) ans = (1ll * ans * base) % mod;

        exp >>= 1;
        base = (1ll * base * base) % mod;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        ans = (ans + pot(m, gcd(i, n))) % mod;
    }

    ans = (1ll * ans * pot(n, mod - 2)) % mod;
    cout << ans << '\n';

    return 0;
}
