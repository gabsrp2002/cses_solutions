#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

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

    int n;
    cin >> n;

    int rot0 = (1ll * n * n) % (mod - 1);
    int rot90 = 1;
    int rot180 = 1;
    if (n & 1) {
        rot90 = (1ll * (n + 3) * (n - 1) / 4 - (n - 1) / 2 + 1) % (mod - 1);
        ;
        rot180 = (1ll * (n + 3) * (n - 1) / 2 - (n - 1) + 1) % (mod - 1);
    } else {
        rot90 = (1ll * n * (n + 2) / 4 - n / 2) % (mod - 1);
        rot180 = (1ll * n * (n + 2) / 2 - n) % (mod - 1);
    }

    int ans = 0;
    ans = (ans + pot(2, rot0)) % mod;
    ans = (ans + pot(2, rot90)) % mod;
    ans = (ans + pot(2, rot180)) % mod;
    ans = (ans + pot(2, rot90)) % mod;
    ans = (1ll * ans * pot(4, mod - 2)) % mod;
    cout << ans << '\n';

    return 0;
}
