#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int pot(int base, int e) {
    int res = 1;
    while (e) {
        if (e & 1)  res = (1ll * base * res) % mod;
        base = (1ll * base * base) % mod;
        e >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int number_of_divisors = 1;
    int exp_number_of_divisors = 1;
    int sum_of_divisors = 1;
    int product_of_divisors = 1;

    int n;
    cin >> n;
    bool found_even = false;
    vector<pair<int, int>> pairs(n);
    while (n--) {
        int x, k;
        cin >> x >> k;
        pairs[n] = {x, k};
        if (!found_even && ((k + 1) % 2 == 0)) {
            exp_number_of_divisors =
                (1ll * ((k + 1) / 2) * exp_number_of_divisors) % (mod - 1);
            found_even = true;
        } else {
            exp_number_of_divisors =
                (1ll * (k + 1) * exp_number_of_divisors) % (mod - 1);
        }

        number_of_divisors = (1ll * (k + 1) * number_of_divisors) % mod;
        sum_of_divisors =
            (1ll * sum_of_divisors *
             ((1ll * (pot(x, k + 1) - 1) * pot(x - 1, mod - 2)) % mod)) %
            mod;

    }
    if (!found_even) {
        for (auto p : pairs)
            product_of_divisors =
                (1ll * product_of_divisors * pot(p.first, p.second / 2)) % mod;
    } else {
        for (auto p : pairs)
            product_of_divisors =
                (1ll * product_of_divisors * pot(p.first, p.second)) % mod;
    }
    product_of_divisors = pot(product_of_divisors, exp_number_of_divisors);
    cout << number_of_divisors << ' ' << sum_of_divisors << ' '
         << product_of_divisors << '\n';

    return 0;
}
