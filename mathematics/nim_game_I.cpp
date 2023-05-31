#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, x, total;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n;
        total = 0;

        for (int i = 0; i < n; i++) {
            cin >> x;
            total = (x + total) - 2 * (x & total);
        }

        if (total) {
            cout << "first" << '\n';
        } else {
            cout << "second" << '\n';
        }
    }

    return 0;
}
