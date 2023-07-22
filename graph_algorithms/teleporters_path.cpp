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
    vector<vector<int>> nei_out(n + 1, vector<int>());
    vector<vector<int>> nei_in(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nei_out[a].push_back(b);
        nei_in[b].push_back(a);
    }
    nei_out[n].push_back(1);
    nei_in[1].push_back(n);

    for (int i = 1; i <= n; i++) {
        if (nei_out[i].size() != nei_in[i].size()) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }

    vector<int> final_path;
    vector<int> curr_path;
    curr_path.push_back(1);
    while (!curr_path.empty()) {
        while (!curr_path.empty() && nei_out[curr_path.back()].empty()) {
            final_path.push_back(curr_path.back());
            curr_path.pop_back();
        }

        if (curr_path.empty()) break;

        int curr = curr_path.back();
        int v = nei_out[curr].back();
        nei_out[curr].pop_back();
        curr_path.push_back(v);
    }
    final_path.pop_back();
    reverse(final_path.begin(), final_path.end());

    if ((int) final_path.size() != m + 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    int i = 0, j = m;
    while (final_path[i] != 1 || final_path[j] != n) {
        i = (i + 1) % (m + 1);
        j = (j + 1) % (m + 1);
    }
    while (i != j) {
        cout << final_path[i] << ' ';
        i = (i + 1) % (m + 1);
    }
    cout << n << '\n';

    return 0;
}
