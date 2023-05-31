#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long
const int mod = 1e9 + 7;

int fac[1000005];
int ifac[1000005];
int freq[26];

int n;

string s;

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

    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        fac[i] = (1ll * i * fac[i - 1]) % mod;
        ifac[i] = pot(fac[i], mod - 2);
    } 

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    int ans = fac[n];

    for (int i = 0; i < 26; i++) {
        ans = (1ll * ans * ifac[freq[i]]) % mod;
    }

    cout << ans << '\n';

    return 0;
}
