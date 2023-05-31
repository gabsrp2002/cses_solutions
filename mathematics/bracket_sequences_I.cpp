#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long
const int mod = 1e9 + 7;

int n;

int pot(int a, int exp) {
    if (!exp) return 1;
    int aux = pot(a, exp / 2);
    aux = (1ll * aux * aux) % mod;
    if (exp & 1) aux = (1ll * aux * a) % mod;
    return aux;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if (n & 1) {
        cout << 0 << '\n';
        return 0;
    }

    int fact = 1;

    for (int i = 1; i <= n / 2 + 1; i++) {
        fact = (1ll * i * fact) % mod;
    }

    int inv = pot(fact, mod - 2);

    fact = 1;
    for (int i = n / 2 + 1; i <= n; i++) {
        fact = (1ll * i * fact) % mod;
    }

    cout << (1ll * fact * inv) % mod << '\n';
    return 0;
}
