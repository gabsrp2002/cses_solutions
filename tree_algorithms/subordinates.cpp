#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, tmp;
vector<int> nei[200005];
int sub[200005];

void dfs(int v) {
    for (int u : nei[v]) {
        dfs(u);
        sub[v] += sub[u] + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> tmp;
        nei[tmp].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << sub[i] << ' ';
    }
    cout << '\n';

    return 0;
}
