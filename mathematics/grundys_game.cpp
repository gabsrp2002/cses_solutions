#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> dp(2000, -1);

    dp[1] = 0;
    for (int i = 2; i < 2000; i++) {
        vector<int> tmp;
        for (int j = 1; 2 * j < i; j++) {
            tmp.push_back(dp[j] ^ dp[i - j]);
        }
        sort(tmp.begin(), tmp.end());
        int ans = 0;
        for (auto item : tmp) {
            if (ans == item) ans++;
        }
        dp[i] = ans;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (n >= 2000 || dp[n] ? "first" : "second") << '\n';
    }

    return 0;
}
