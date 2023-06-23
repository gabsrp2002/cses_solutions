#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    int k;
    cin >> n >> k;
    vector<ll> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int mask = 1; mask < (1 << k); mask++) {
        __int128 current_product = 1;
        int sign = -1;
        for (int i = 0; i < k; i++) {
            if (mask & (1 << i)) {
                current_product *= a[i];
                if (current_product > n) break;
                sign = -sign;
            }
        }
        ans += sign * (n / current_product);
    }

    cout << ans << '\n';

    return 0;
}
