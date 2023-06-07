#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int n, x;
int h[1005], s[1005];
int dp[1005][100005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= h[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s[i]);
        }
    }

    cout << dp[n][x] << '\n';

    return 0;
}
