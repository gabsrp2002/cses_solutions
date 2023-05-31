#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, x;
set<pair<int, int>> s;
vector<int> h;
int a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (2 * a == x) {
            h.push_back(i);
            continue;
        }
        s.insert({a, i});
    }

    if (h.size() > 1) {
        cout << h[0] + 1 << ' ' << h[1] + 1 << '\n';
        return 0;
    }

    for (auto p : s) {
        if (p.first >= x) break;
        int goal = x - p.first;
        auto it = s.lower_bound({goal, -1});
        if (it == s.end()) continue;
        if (it->first == goal) {
            cout << p.second + 1 << ' ' << it->second + 1 << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
