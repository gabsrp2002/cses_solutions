#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, last, x;
ll ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    cin >> last;

    for (int i = 0; i < n - 1; i++) {
        cin >> x;

        ans += ((last > x) ? (last - x) : 0);

        if (x > last) last = x;
    }

    cout << ans << '\n';
    return 0;
}
