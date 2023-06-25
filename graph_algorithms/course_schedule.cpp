#include <bits/stdc++.h>
#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

vector<int> nei[100005];
vector<int> course_order;
int vis[100005];

int dfs(int curr) {
    if (vis[curr] == 1) return -1;
    if (vis[curr] == 2) return 0;
    vis[curr] = 1;
    for (auto v : nei[curr]) {
        if (dfs(v) == -1) return -1;
    }
    vis[curr] = 2;
    course_order.push_back(curr);
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] != 2 && dfs(i) == -1) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
    }
    reverse(course_order.begin(), course_order.end());
    for (auto course : course_order) {
        cout << course << ' ';
    }
    cout << '\n';

    return 0;
}
