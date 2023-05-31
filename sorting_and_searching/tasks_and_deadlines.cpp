#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll sum;
int n;
int a[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        int d;
        cin >> d;
        sum += d;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        sum -= 1ll * (n - i) * a[i];
    }

    cout << sum << '\n';

    return 0;
}
