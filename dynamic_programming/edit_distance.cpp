#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int dp[5005][5005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    for (int i = 0; i <= (int) s1.size(); i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= (int) s2.size(); i++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= (int) s1.size(); i++) {
        for (int j = 1; j <= (int) s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] =
                    min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }

    cout << dp[s1.size()][s2.size()] << '\n';

    return 0;
}
