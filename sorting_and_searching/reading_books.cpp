#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
ll t, s, MAXIMUM;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--) {
        cin >> t;
        s += t;
        MAXIMUM = max(MAXIMUM, t);
    }

    cout << max(s, 2 * MAXIMUM) << '\n';

    return 0;
}
