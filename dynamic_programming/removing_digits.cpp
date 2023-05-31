#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
int dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[i] = i + 1; 
        int cp = i;
        while (cp) {
            int digit = cp % 10;
            dp[i] = min(dp[i], dp[i - digit] + 1);
            cp /= 10;
        }
    }
    cout << dp[n] << '\n';

    return 0;
}
