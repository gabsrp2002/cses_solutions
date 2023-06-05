#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(6);
    cout.setf(ios::fixed);

    cin >> n >> k;
    double ans = k;
    for (int i = 1; i < k; i++) {
        double curr = 1;
        for (int j = 0; j < n; j++) {
            curr = (curr * i) / (double) k;
        }
        ans -= curr;
    }

    cout << ans << '\n';

    return 0;
}
