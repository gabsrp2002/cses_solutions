#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n;
vector<int> nei[200005];
int a, b;
int best;
int best_node = 1;

int dfs(int v, int pai, int c = 0) {
    int ans = 0;
    for (auto u : nei[v]) {
        if (u != pai) {
            ans = max(ans, dfs(u, v, c + 1));
        }
    }

    if (c > best) {
        best = c;
        best_node = v;
    }
    return max(ans, c);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;   
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    dfs(1, -1);

    cout << dfs(best_node, -1) << '\n';

    return 0;
}
