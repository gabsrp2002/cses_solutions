#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

char helper[1005][1005];
vector<pair<int, int>> monsters_pos;
vector<pair<int, int>> hero_pos;
pair<int, int> pi[1005][1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> helper[i][j];
            if (helper[i][j] == 'M') {
                monsters_pos.push_back({i, j});
                helper[i][j] = '#';
            } else if (helper[i][j] == 'A') {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    cout << "YES" << '\n';
                    cout << 0 << '\n';
                    return 0;
                }
                hero_pos.push_back({i, j});
                pi[i][j] = {-1, -1};
            }
        }
    }

    pair<int, int> final_pos = {-1, -1};
    while (!hero_pos.empty()) {
        vector<pair<int, int>> tmp_monsters(0);
        vector<pair<int, int>> tmp_hero(0);

        for (auto p : monsters_pos) {
            if (p.first >= 1 && helper[p.first - 1][p.second] == '.') {
                tmp_monsters.push_back({p.first - 1, p.second});
                helper[p.first - 1][p.second] = '#';
            }
            if (p.first < n - 1 && helper[p.first + 1][p.second] == '.') {
                tmp_monsters.push_back({p.first + 1, p.second});
                helper[p.first + 1][p.second] = '#';
            }
            if (p.second >= 1 && helper[p.first][p.second - 1] == '.') {
                tmp_monsters.push_back({p.first, p.second - 1});
                helper[p.first][p.second - 1] = '#';
            }
            if (p.second < m - 1 && helper[p.first][p.second + 1] == '.') {
                tmp_monsters.push_back({p.first, p.second + 1});
                helper[p.first][p.second + 1] = '#';
            }
        }

        for (auto p : hero_pos) {
            if (p.first >= 1 && helper[p.first - 1][p.second] == '.') {
                tmp_hero.push_back({p.first - 1, p.second});
                helper[p.first - 1][p.second] = 'U';
                pi[p.first - 1][p.second] = p;
                if (p.first - 1 == 0) {
                    final_pos = {p.first - 1, p.second};
                    break;
                }
            }
            if (p.first < n - 1 && helper[p.first + 1][p.second] == '.') {
                tmp_hero.push_back({p.first + 1, p.second});
                helper[p.first + 1][p.second] = 'D';
                pi[p.first + 1][p.second] = p;
                if (p.first + 1 == n - 1) {
                    final_pos = {p.first + 1, p.second};
                    break;
                }
            }
            if (p.second >= 1 && helper[p.first][p.second - 1] == '.') {
                tmp_hero.push_back({p.first, p.second - 1});
                helper[p.first][p.second - 1] = 'L';
                pi[p.first][p.second - 1] = p;
                if (p.second - 1 == 0) {
                    final_pos = {p.first, p.second - 1};
                    break;
                }
            }
            if (p.second < m - 1 && helper[p.first][p.second + 1] == '.') {
                tmp_hero.push_back({p.first, p.second + 1});
                helper[p.first][p.second + 1] = 'R';
                pi[p.first][p.second + 1] = p;
                if (p.second + 1 == m - 1) {
                    final_pos = {p.first, p.second + 1};
                    break;
                }
            }
        }

        if (final_pos.first != -1) break;

        hero_pos.clear();
        monsters_pos.clear();
        for (auto p : tmp_hero) {
            hero_pos.push_back(p);
        }
        for (auto p : tmp_monsters) {
            monsters_pos.push_back(p);
        }
    }

    if (final_pos.first == -1) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    string ans = "";
    int i = final_pos.first, j = final_pos.second;
    int counter = 0;
    while (pi[i][j].first != -1) {
        ans += helper[i][j];
        int tmp = pi[i][j].first;
        j = pi[i][j].second;
        i = tmp;
        counter++;
    }
    cout << counter << '\n';
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';

    return 0;
}
