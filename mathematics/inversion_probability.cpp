#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, r[101];
double ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(6);
    cout.setf(ios::fixed);

    cin >> n;    
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += (min(r[i], r[j]) * (r[i] - (min(r[i], r[j]) + 1) / 2.0)) / (r[i] * r[j]);
        }
    }

    cout << ans << '\n';

    return 0;
}
