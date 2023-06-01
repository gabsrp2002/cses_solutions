#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> s(n + 1, 0);
    set<int> divisors;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1] + (1ll * n * 1e9);
        s[i] %= n;
    }
    ll ans = 0;
    map<ll, int> prevsum;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 0) ans++;

        ans += prevsum[s[i]];
        prevsum[s[i]]++;
    }

    cout << ans << '\n';

    return 0;
}
