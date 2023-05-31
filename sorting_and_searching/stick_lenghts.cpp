#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n;
int p[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    int ini = 0, end = n - 1;
    ll ans = 0;
    while (ini < end) {
        ans += p[end] - p[ini];
        ini++;
        end--;
    }

    cout << ans << '\n';

    return 0;
}
