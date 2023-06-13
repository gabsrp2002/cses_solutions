#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

bool dp[100005][105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int val = 1; val <= 100000; val++) {
            dp[val][i] = dp[val][i - 1];
            if (val >= x[i]) dp[val][i] |= dp[val - x[i]][i - 1];
        }
    }

    int counter = 0;
    for (int val = 1; val <= 100000; val++) {
        if (dp[val][n]) counter++;
    }
    cout << counter << '\n';
    for (int val = 1; val <= 100000; val++) {
        if (dp[val][n]) cout << val << ' ';
    }
    cout << '\n';


    return 0;
}
