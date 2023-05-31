#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int m, n;
char labyrinth[1005][1005];
int startx, starty;
int endx, endy;
char direction[1005][1005];

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty()) {
        auto pa = q.front();
        q.pop();
        i = pa.first;
        j = pa.second;

        if (i + 1 < m && labyrinth[i + 1][j] != '#' &&
            labyrinth[i + 1][j] != 'B') {
            direction[i + 1][j] = 'U';
            if (labyrinth[i + 1][j] == 'A') break;
            labyrinth[i + 1][j] = '#';
            q.push({i + 1, j});
        }
        if (i - 1 >= 0 && labyrinth[i - 1][j] != '#' &&
            labyrinth[i - 1][j] != 'B') {
            direction[i - 1][j] = 'D';
            if (labyrinth[i - 1][j] == 'A') break;
            labyrinth[i - 1][j] = '#';
            q.push({i - 1, j});
        }
        if (j + 1 < n && labyrinth[i][j + 1] != '#' &&
            labyrinth[i][j + 1] != 'B') {
            direction[i][j + 1] = 'L';
            if (labyrinth[i][j + 1] == 'A') break;
            labyrinth[i][j + 1] = '#';
            q.push({i, j + 1});
        }
        if (j - 1 >= 0 && labyrinth[i][j - 1] != '#' &&
            labyrinth[i][j - 1] != 'B') {
            direction[i][j - 1] = 'R';
            if (labyrinth[i][j - 1] == 'A') break;
            labyrinth[i][j - 1] = '#';
            q.push({i, j - 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> labyrinth[i][j];
            if (labyrinth[i][j] == 'A') {
                startx = i;
                starty = j;
            }
            if (labyrinth[i][j] == 'B') {
                endx = i;
                endy = j;
            }
        }
    }
    direction[startx][starty] = 'E';

    bfs(endx, endy);

    if (direction[startx][starty] == 'E') {
        cout << "NO" << '\n';
        return 0;
    }

    string ans = "";

    while (endx != startx || starty != endy) {
        ans += direction[startx][starty];
        if (direction[startx][starty] == 'U') startx--;
        else if (direction[startx][starty] == 'D') startx++;
        else if (direction[startx][starty] == 'L') starty--;
        else if (direction[startx][starty] == 'R') starty++;
    }
    cout << "YES" << '\n';
    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}
