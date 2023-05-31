#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long
const int mod = 1e9 + 7;

int fact[1000005];
int ifact[1000005];
int n, a, b;

int pot(int base, int exp) {
    if (!exp) return 1;
    int aux = pot(base, exp / 2);
    aux = (1ll * aux * aux) % mod;
    if (exp & 1) aux = (1ll * aux * base) % mod;

    return aux;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    fact[0] = ifact[0] = 1;

    for (int i = 1; i <= 1000000; i++) {
        fact[i] = (1ll * i * fact[i - 1]) % mod;
        ifact[i] = pot(fact[i], mod - 2);
    }

    cin >> n;

    while (n--) {
        cin >> a >> b;

        cout << (1ll * ((1ll * fact[a] * ifact[b]) % mod) * ifact[a - b]) % mod
             << '\n';
    }

    return 0;
}
