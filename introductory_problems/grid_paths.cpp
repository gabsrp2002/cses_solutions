#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

string s;
int used[7][7];
int ans;

void backtrack(int n, int x, int y) {
    if (x == 6 && y == 0) {
        if (n == 48) ans++;
        return;
    }
    
    if (x > 0 && x < 6 && y > 0 && y < 6) {
        if ((!used[x - 1][y] && !used[x + 1][y] && used[x][y - 1] && used[x][y + 1]) || (used[x - 1][y] && used[x + 1][y] && !used[x][y - 1] && !used[x][y + 1])) return;
    }

    if (x == 0 && y > 0 && y < 6) {
        if (used[x + 1][y] && !used[x][y - 1] && !used[x][y + 1]) return;
    }

    if (x == 6 && y > 0 && y < 6) {
        if (used[x - 1][y] && !used[x][y - 1] && !used[x][y + 1]) return;
    }

    if (y == 6 && x > 0 && x < 6) {
        if (used[x][y - 1] && !used[x - 1][y] && !used[x + 1][y]) return;
    }

    if (y == 0 && x > 0 && x < 6) {
        if (used[x][y + 1] && !used[x - 1][y] && !used[x + 1][y]) return;
    }

    switch (s[n]) {
        case '?':
            if (x - 1 >= 0) {
                if (!used[x - 1][y]) {
                    s[n] = 'U';
                    used[x - 1][y] = 1;
                    backtrack(n + 1, x - 1, y);
                    used[x - 1][y] = 0;
                    s[n] = '?';
                }
            }
            if (x + 1 <= 6) {
                if (!used[x + 1][y]) {
                    s[n] = 'D';
                    used[x + 1][y] = 1;
                    backtrack(n + 1, x + 1, y);
                    used[x + 1][y] = 0;
                    s[n] = '?';
                }
            }
            if (y - 1 >= 0) {
                if (!used[x][y - 1]) {
                    s[n] = 'L';
                    used[x][y - 1] = 1;
                    backtrack(n + 1, x, y - 1);
                    used[x][y - 1] = 0;
                    s[n] = '?';
                }
            }
            if (y + 1 <= 6) {
                if (!used[x][y + 1]) {
                    s[n] = 'R';
                    used[x][y + 1] = 1;
                    backtrack(n + 1, x, y + 1);
                    used[x][y + 1] = 0;
                    s[n] = '?';
                }
            }
            break;
        case 'U':
            if (x - 1 >= 0) {
                if (!used[x - 1][y]) {
                    used[x - 1][y] = 1;
                    backtrack(n + 1, x - 1, y);
                    used[x - 1][y] = 0;
                }
            }
            break;
        case 'D':
            if (x + 1 <= 6) {
                if (!used[x + 1][y]) {
                    used[x + 1][y] = 1;
                    backtrack(n + 1, x + 1, y);
                    used[x + 1][y] = 0;
                }
            }
            break;
        case 'L':
            if (y - 1 >= 0) {
                if (!used[x][y - 1]) {
                    used[x][y - 1] = 1;
                    backtrack(n + 1, x, y - 1);
                    used[x][y - 1] = 0;
                }
            }
            break;
        case 'R':
            if (y + 1 <= 6) {
                if (!used[x][y + 1]) {
                    used[x][y + 1] = 1;
                    backtrack(n + 1, x, y + 1);
                    used[x][y + 1] = 0;
                }
            }
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    used[0][0] = 1;

    cin >> s;

    backtrack(0, 0, 0);

    cout << ans << '\n';

    return 0;
}
