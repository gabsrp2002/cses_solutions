#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
char table[1005][1005];

int dfs(int i, int j) {
    if (table[i][j] == '#') return 0;

    table[i][j] = '#';
    
    if (i + 1 < m) dfs(i + 1, j);
    if (i - 1 >= 0) dfs(i - 1, j);
    if (j + 1 < n) dfs(i, j + 1);
    if (j - 1 >= 0) dfs(i, j - 1);

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
    }

    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res += dfs(i, j);
        }
    }

    cout << res << '\n';

    return 0;
}
