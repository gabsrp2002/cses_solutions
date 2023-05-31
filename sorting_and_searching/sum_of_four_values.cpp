#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
ll x, a[1005];

vector<pair<int, pair<int, int> > > sums;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            sums.push_back({a[i] + a[j], {i + 1, j + 1}});
        }
    }

    sort(sums.begin(), sums.end());

    for (auto it = sums.begin(); it != sums.end(); it++) {
        ll goal = x - it->first;
        if (goal <= 0) continue;

        pair<int, pair<int, int> > search = {goal, {it->second.second + 1, -1}};

        auto found = upper_bound(sums.begin(), sums.end(), search);
        if (found == sums.end()) continue;

        if (found->first == goal) {
            cout << it->second.first << ' ' << it->second.second << ' ' << found->second.first << ' ' << found->second.second << '\n';
            return 0;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
    return 0;
}
