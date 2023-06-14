#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int a[1000005], b[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    a[1] = b[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        a[i] = (2ll * a[i - 1] + b[i - 1]) % mod;
        b[i] = (4ll * b[i - 1] + a[i - 1]) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (a[n] + b[n]) % mod << '\n';
    }

    return 0;
}
