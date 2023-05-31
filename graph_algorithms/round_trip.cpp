#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
vector<int> nei[100005];
vector<int> route;
bool in_use[100005];
bool seen[100005];
int start;

int dfs(int curr, int last = -1) {
    seen[curr] = 1;
    route.push_back(curr);

    if (in_use[curr]) {
        start = curr;
        return 1;
    }

    in_use[curr] = 1;

    for (auto v : nei[curr]) {
        if (v == last) continue;
        if (dfs(v, curr)) return 1;
    }

    route.pop_back();

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    bool works = false;

    for (int i = 1; i <= n; i++) {
        if (!seen[i]) {
            if (dfs(i)) {
                works = true;
                break;
            }
        }
    }

    if (!works) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    int index = 0;
    while (route[index] != start) index++;

    int s = route.size();

    cout << s - index << '\n';

    for (int i = index; i < s; i++) {
        cout << route[i] << ' ';
    }
    cout << '\n';

    return 0;
}
