#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int dp[505][250005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int total = (n * (n + 1)) / 2;
    if (total & 1) {
        cout << 0 << '\n';
        return 0;
    }
    total /= 2;

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= total; j++) {
            if (j < i) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - i]) % mod;
            }
        }
    }

    cout << dp[n][total] << '\n';

    return 0;
}
