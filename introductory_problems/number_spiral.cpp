#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> x >> y;

        if (y >= x) {
            if (y & 1) {
                cout << y * y + 1 - x << '\n';
            } else {
                cout << (y - 1) * (y - 1) + x << '\n';
            }
        } else {
            if (x & 1) {
                cout << (x - 1) * (x - 1) + y << '\n';
            } else {
                cout << x * x + 1 - y << '\n';
            }
        }
    }

    return 0;
}
