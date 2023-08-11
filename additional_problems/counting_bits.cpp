#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

ll get_ans(ll n) {
    if (n == 0) return 0;
    ll pot = 1;

    int exponent = 0;
    while (pot * 2 <= n) {
        pot *= 2;
        exponent++;
    }

    return (exponent * pot / 2) + (n - pot + 1) + get_ans(n - pot);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    cout << get_ans(n) << '\n';

    return 0;
}
