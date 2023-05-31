#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, goal;
ll a[200005], s[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> goal;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] > goal) continue;

        int start = 1, end = n + 1;

        while (start + 1 != end) {
            int mid = (start + end) / 2;
            if (s[mid] - s[i - 1] <= goal) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (s[start] - s[i - 1] == goal) ans++;
    }

    cout << ans << '\n';

    return 0;
}
