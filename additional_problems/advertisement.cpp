#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
vector<pair<int, int>> k;
set<pair<int, int>> intervals;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        k.push_back({tmp, i});
    }
    sort(k.rbegin(), k.rend());
    intervals.insert({0, n - 1});
    ll ans = 0;
    while (!k.empty()) {
        auto curr = k.back();
        k.pop_back();
        int i = curr.second;
        auto it = intervals.lower_bound({i, n});
        it--;
        ans = max(ans, 1ll * curr.first * (it->second - it->first + 1));
        if (i > it->first) intervals.insert({it->first, i - 1});
        if (i < it->second) intervals.insert({i + 1, it->second});

        intervals.erase(it);
    }

    cout << ans << '\n';

    return 0;
}
