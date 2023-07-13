#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

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

        int hash1 = get_hash(1, nei1);
        int hash2 = get_hash(1, nei2);

        cout << (hash1 == hash2 ? "YES" : "NO") << '\n';
    }

    return 0;
}
