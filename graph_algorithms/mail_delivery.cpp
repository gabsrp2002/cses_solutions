#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<set<int>> nei(n + 1, set<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].insert(b);
        nei[b].insert(a);
    }

    for (int i = 1; i <= n; i++) {
        if (nei[i].size() & 1) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    vector<int> final_path;
    vector<int> curr_path;
    curr_path.push_back(1);
    while (!curr_path.empty()) {
        while (!curr_path.empty() && nei[curr_path.back()].empty()) {
            final_path.push_back(curr_path.back());
            curr_path.pop_back();
        }

        if (curr_path.empty()) break;

        int curr = curr_path.back();
        int v = *nei[curr].begin();
        nei[curr].erase(v);
        nei[v].erase(curr);
        curr_path.push_back(v);
    }

    if ((int) final_path.size() != m + 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    for (auto v : final_path) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}
