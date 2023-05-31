#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, x, c[200];
int dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    memset(dp, -1, sizeof dp);

    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j] && dp[i - c[j]] != -1) {
                if (dp[i] == -1)
                    dp[i] = dp[i - c[j]] + 1;
                else
                    dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        } 
    }
    cout << dp[x] << '\n';

    return 0;
}
