#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;

const int mod = 1e9 + 7;

int dp[1005][1005];
char grid[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    dp[0][0] = (grid[0][0] == '.');

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;

            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];

            dp[i][j] %= mod;
        }
    }

    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}
