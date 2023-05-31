#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
vector<int> nei[200005];
int dp[200005];

void dfs(int curr, int par = -1) {
    for (auto v : nei[curr]) {
        if (v == par) continue;
        dfs(v, curr);
        dp[curr] = max(dp[curr], 1 - dp[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    dfs(1);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
    }
    cout << ans << '\n';

    return 0;
}
