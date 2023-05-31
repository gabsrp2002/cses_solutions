#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
vector<int> nei[200005];
int first_max[200005];
int second_max[200005];
int to[200005];

void bottom_up_dfs(int curr, int par = -1) {
    for (auto v : nei[curr]) {
        if (v == par) continue;
        bottom_up_dfs(v, curr);
        if (first_max[v] + 1 > first_max[curr]) {
            second_max[curr] = first_max[curr];
            first_max[curr] = first_max[v] + 1;
            to[curr] = v;
        } else if (first_max[v] + 1 > second_max[curr]) {
            second_max[curr] = first_max[v] + 1;
        }
    }
}

void top_down_dfs(int curr, int par = -1) {
    for (auto v : nei[curr]) {
        if (v == par) continue;

        if (to[curr] == v) {
            if (first_max[v] < second_max[curr] + 1) {
                second_max[v] = first_max[v];
                first_max[v] = second_max[curr] + 1;
                to[v] = curr;
            } else if (second_max[v] < second_max[curr] + 1) {
                second_max[v] = second_max[curr] + 1;
            }
        } else {
            second_max[v] = first_max[v];
            first_max[v] = first_max[curr] + 1;
            to[v] = curr;
        }

        top_down_dfs(v, curr);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nei[a].push_back(b);
        nei[b].push_back(a);
    }

    bottom_up_dfs(1);
    top_down_dfs(1);

    for (int i = 1; i <= n; i++) {
        cout << first_max[i] << ' ';
    }
    
    return 0;
}
