#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
int x, y;
ll b, I;
pair<ll, ll> vertex[10005];

int gcd(int a, int b) {
    if (!a || !b) return a + b;
    return gcd(b, a % b);
}

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

    for (int i = 0; i < n - 1; i++) {
        b += gcd(abs(vertex[i].first - vertex[i + 1].first),
                 abs(vertex[i].second - vertex[i + 1].second));
    }
    b += gcd(abs(vertex[0].first - vertex[n - 1].first),
             abs(vertex[0].second - vertex[n - 1].second));

    area = abs(area);

    I = (area - b + 2) / 2;

    cout << I << ' ' << b << '\n';

    return 0;
}
