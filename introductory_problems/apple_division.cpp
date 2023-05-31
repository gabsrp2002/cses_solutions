#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
int pot[25];
int p[25];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    ll s = 0;
    for (int i = 0; i < n; i++) {
        pot[i] = 1 << i;
        cin >> p[i];
        s += p[i];
    }

    ll ans = s;

    for (int i = 0; i < (1 << n); i++) {
        ll partial = 0;
        for (int j = 0; j < n; j++) {
            if (i & pot[j]) {
                partial += p[j];
            }
        }
        ans = min(ans, abs(s - 2 * partial));
    }

    cout << ans << '\n';

    return 0;
}
