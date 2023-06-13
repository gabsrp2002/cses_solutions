#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

ll dp[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> intervals(n + 1);
    intervals[0] = {{INT_MAX, INT_MAX}, INT_MAX};
    for (int i = 1; i <= n; i++) {
        cin >> intervals[i].first.first >> intervals[i].first.second >>
            intervals[i].second;
    }

    sort(intervals.begin() + 1, intervals.end(),
         greater<pair<pair<int, int>, int>>());

    for (int i = 1; i <= n; i++) {
        int start = 0, end = i;
        while (start + 1 != end) {
            int mid = (start + end) / 2;
            if (intervals[mid].first.first > intervals[i].first.second)
                start = mid;
            else
                end = mid;
        }

        dp[i] = max(dp[i - 1], dp[start] + intervals[i].second);
    }

    cout << dp[n] << '\n';

    return 0;
}
