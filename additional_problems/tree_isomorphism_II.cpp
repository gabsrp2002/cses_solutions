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

pair<int, int> rec_find_centroid(int root, vector<vector<int>> &adj, vector<int> &sub_sizes, int n, int par = -1) {
    int max_nei = 0;
    for (auto v : adj[root]) {
        if (v == par) continue;
        if (sub_sizes[v] > sub_sizes[max_nei]) {
            max_nei = v;
        }
    }
    if (sub_sizes[max_nei] <= n / 2) return {root, max_nei};

    return rec_find_centroid(max_nei, adj, sub_sizes, n, root);
}

pair<int, int> find_centroid(int n, vector<vector<int>> &adj) {
    vector<int> sub_sizes = get_subtree_sizes(n, adj);

    return rec_find_centroid(1, adj, sub_sizes, n);
}

map<vector<int>, int> hasher;

int hashify(vector<int> x) {
    sort(x.begin(), x.end());
    if(!hasher[x]) {
        hasher[x] = hasher.size();
    }
    return hasher[x];
}

int get_hash(int v, vector<vector<int>> &g, int par = -1) { 
    vector<int> children;
    for(int u: g[v]) {
        if (u == par) continue;
        children.push_back(get_hash(u, g, v));
    }
    return hashify(children);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> nei1(n + 1, vector<int>());
        vector<vector<int>> nei2(n + 1, vector<int>());
        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nei1[a].push_back(b);
            nei1[b].push_back(a);
        }

        for (int i = 0; i < n - 1; i++) {
            int a, b;
            cin >> a >> b;
            nei2[a].push_back(b);
            nei2[b].push_back(a);
        }

        auto p1 = find_centroid(n, nei1);
        auto p2 = find_centroid(n, nei2);

        int hash1 = get_hash(p1.first, nei1);
        int hash2 = get_hash(p2.first, nei2);
        int hash3 = get_hash(p2.second, nei2);

        cout << ((hash1 == hash2 || hash1 == hash3) ? "YES" : "NO") << '\n';
    }

    return 0;
}
