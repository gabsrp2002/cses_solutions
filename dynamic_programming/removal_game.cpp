#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

pair<ll, ll> dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i][i] = {x[i], 0}; // Distance = 0
    }

    for (int k = 1; k < n; k++) {  // Distance between i and j
        for (int i = 0; i < n - k; i++) {
            int j = i + k;
            if (dp[i][j - 1].second + x[j] > dp[i + 1][j].second + x[i]) {
                dp[i][j] = {dp[i][j - 1].second + x[j], dp[i][j - 1].first};
            } else {
                dp[i][j] = {dp[i + 1][j].second + x[i], dp[i + 1][j].first};
            }
            /* cout << "dp[" << i << "][" << j << "] = {" << dp[i][j].first << ", " << dp[i][j].second << "}" << '\n'; */
        }
    }
    cout << dp[0][n - 1].first << '\n';

    return 0;
}
