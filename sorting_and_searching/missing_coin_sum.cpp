#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n;
int x[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);

    ll s = 0;

    for (int i = 0; i < n; i++) {
        if (x[i] > s + 1) {
            break;
        }
        s += x[i];
    }

    cout << s + 1 << '\n';

    return 0;
}
