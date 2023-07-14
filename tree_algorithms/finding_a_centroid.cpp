#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

void rec_subtree_sizes(int root, vector<vector<int>> &adj, vector<int> &sizes, int par = -1) {
    sizes[root] = 1;
    for (auto v : adj[root]) {
        if (v == par) continue;        
        rec_subtree_sizes(v, adj, sizes, root);

        sizes[root] += sizes[v];
    }
}

vector<int> get_subtree_sizes(int n, vector<vector<int>> &adj) {
    vector<int> sizes(n + 1);

    rec_subtree_sizes(1, adj, sizes);

    return sizes;
}

int rec_find_centroid(int root, vector<vector<int>> &adj, vector<int> &sub_sizes, int n, int par = -1) {
    int max_nei = 0;
    for (auto v : adj[root]) {
        if (v == par) continue;
        if (sub_sizes[v] > sub_sizes[max_nei]) {
            max_nei = v;
        }
    }
    if (sub_sizes[max_nei] <= n / 2) return root;

    return rec_find_centroid(max_nei, adj, sub_sizes, n, root);
}

int find_centroid(int n, vector<vector<int>> &adj) {
    vector<int> sub_sizes = get_subtree_sizes(n, adj);

    return rec_find_centroid(1, adj, sub_sizes, n);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << find_centroid(n, adj) << '\n';

    return 0;
}
