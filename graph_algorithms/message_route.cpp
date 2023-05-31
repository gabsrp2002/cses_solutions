#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
vector<int> nei[100005];
int p[100005];

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

    queue<int> q;
    p[1] = -1;
    q.push(1);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (auto v : nei[curr]) {
            if (p[v] == 0) {
                p[v] = curr;
                q.push(v);
            }
        }
    }

    if (p[n] == 0) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    vector<int> ans;
    int curr = n;
    while (curr != -1) {
        ans.push_back(curr);
        curr = p[curr];
    } 

    int s = ans.size();
    cout << s << '\n';
    for (int i = s - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
