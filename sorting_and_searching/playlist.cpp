#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
vector<int> k;
set<pair<int, int> > places;
int dp[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    places.insert({-1, -1});
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        k.push_back(tmp);
        places.insert({tmp, i});
    }

    for (int i = 1; i < n; i++) {
        auto it = places.find({k[i], i});
        it--;
        if (it->first == k[i])
            dp[i] = max(dp[i - 1], it->second + 1);
        else
            dp[i] = dp[i - 1];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, i - dp[i]);
    }

    cout << ans + 1 << '\n';

    return 0;
}
