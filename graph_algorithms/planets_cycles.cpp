#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> t(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i]) {
            cout << dp[i] << ' ';
            continue;
        }

        int curr = i;
        vector<int> path;
        while (!vis[curr] && !dp[curr]) {
            vis[curr] = 1;
            path.push_back(curr);
            curr = t[curr];
        }
        if (dp[curr]) {
            int dist = 1;
            while (!path.empty()) {
                int next = path.back();
                path.pop_back();
                dp[next] = dp[curr] + dist;
                dist++;
            }
        } else {
            int pos = 0;
            while (path[pos] != curr) pos++;
            int dist = (int) path.size() - pos;
            while (path.back() != curr) {
                dp[path.back()] = dist;
                path.pop_back();
            }
            while (!path.empty()) {
                dp[path.back()] = dist;
                path.pop_back();
                dist++;
            }
        }

        cout << dp[i] << ' ';
    }
    cout << '\n';

    return 0;
}
