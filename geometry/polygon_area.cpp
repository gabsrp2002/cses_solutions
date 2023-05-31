#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
pair<ll, ll> vertex[1005];
ll x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;

        vertex[i] = {x, y};
    }

    ll area = 0;

    for (int i = n - 1; i >= 2; i--) {
        area += (vertex[i].first - vertex[0].first) *
                    (vertex[i - 1].second - vertex[0].second) -
                (vertex[i - 1].first - vertex[0].first) *
                    (vertex[i].second - vertex[0].second);
    }

    cout << abs(area) << '\n';

    return 0;
}
