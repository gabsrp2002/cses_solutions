#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int dp[100005][105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    if (x[0] == 0) {
        for (int i = 1; i <= m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int val = 1; val <= m; val++) {
                for (int a = -1; a <= 1; a++) {
                    dp[i][val] += dp[i - 1][val + a];
                    dp[i][val] %= mod;
                }
            }
        } else {
            for (int a = -1; a <= 1; a++) {
                dp[i][x[i]] += dp[i - 1][x[i] + a];
                dp[i][x[i]] %= mod;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}
