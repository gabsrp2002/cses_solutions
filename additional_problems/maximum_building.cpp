#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
vector<vector<int>> tree_pos;
vector<pair<int, int>> k;
set<pair<int, int>> intervals;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> curr_tree_pos;
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            if (tmp == '*') {
                curr_tree_pos.push_back(j);
            }
        }
        curr_tree_pos.push_back(m);
        tree_pos.push_back(curr_tree_pos);
    }
    ll ans = 0;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            k.push_back({*lower_bound(tree_pos[i].begin(), tree_pos[i].end(), j) - j, i});
        }
        sort(k.rbegin(), k.rend());
        intervals.insert({0, n - 1});
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
        intervals.clear();
    }

    cout << ans << '\n';

    return 0;
}
