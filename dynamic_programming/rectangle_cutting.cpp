#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int dp[505][505];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin >> a >> b;

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            dp[i][j] = INT_MAX;            
        }
    }
    for (int i = 1; i <= 500; i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= 500; i++) {
        for (int j = 1; j <= 500; j++) {
            if (i == j) continue;
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[k][j] + dp[i - k][j], dp[i][j]);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][k] + dp[i][j - k], dp[i][j]);
            }
            dp[i][j]++;
        }
    }

    cout << dp[a][b] << '\n';

    return 0;
}
