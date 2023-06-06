#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

const int mod = 1e9 + 7;

int dp[100005];

int dfs(int curr, vector<vector<int>> &nei) {
    if (dp[curr] != -1) return dp[curr];
    dp[curr] = 0;
    for (auto v : nei[curr]) {
        dp[curr] = (dfs(v, nei) + dp[curr]) % mod;
    }

    return dp[curr];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> nei = vector<vector<int>>(n);

    while (m--) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        nei[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    cout << dfs(n - 1, nei) << '\n';

    return 0;
}
