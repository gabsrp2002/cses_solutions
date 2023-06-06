#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

const int mod = 1e9 + 7;

int n, x;
int c[105];
int dp[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    dp[0] = 1;

    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= x; i++) {
            if (i < c[j]) continue;
            dp[i] = (dp[i] + dp[i - c[j]]) % mod;
        }
    }

    cout << dp[x] << '\n';


    return 0;
}
