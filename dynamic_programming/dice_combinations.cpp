#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long
const int mod = 1e9 + 7;

int n;
int dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    dp[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i - 1; j >= max(0, i - 6); j--) {
            dp[i] = (dp[j] + dp[i]) % mod;
        }
    }

    cin >> n;
    cout << dp[n] << '\n';

    return 0;
}
