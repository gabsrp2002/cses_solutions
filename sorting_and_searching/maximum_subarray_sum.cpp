#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
ll x[200005];
ll sub[200005];
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    ans = sub[0] = x[0];
    for (int i = 1; i < n; i++) {
        sub[i] = max(x[i], sub[i - 1] + x[i]);
        ans = max(ans, sub[i]);
    }

    cout << ans << '\n';

    return 0;
}
