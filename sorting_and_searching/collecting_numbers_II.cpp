#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m, tmp;
int pos[200005];
int number_in_pos[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    pos[0] = 0;
    pos[n + 1] = n + 1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pos[tmp] = i + 1;
        number_in_pos[i + 1] = tmp;
    }

    int ans = 1;

    for (int i = 1; i < n; i++) {
        ans += (pos[i] > pos[i + 1]);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        if (number_in_pos[a] > number_in_pos[b]) swap(a, b);

        if (number_in_pos[b] > number_in_pos[a] + 1) {
            ans -= (pos[number_in_pos[a] - 1] > pos[number_in_pos[a]]) + (pos[number_in_pos[a]] > pos[number_in_pos[a] + 1]) + (pos[number_in_pos[b] - 1] > pos[number_in_pos[b]]) + (pos[number_in_pos[b]] > pos[number_in_pos[b] + 1]);

            swap(pos[number_in_pos[a]], pos[number_in_pos[b]]);

            ans += (pos[number_in_pos[a] - 1] > pos[number_in_pos[a]]) + (pos[number_in_pos[a]] > pos[number_in_pos[a] + 1]) + (pos[number_in_pos[b] - 1] > pos[number_in_pos[b]]) + (pos[number_in_pos[b]] > pos[number_in_pos[b] + 1]);
            swap(number_in_pos[a], number_in_pos[b]);
        } else {
            ans -= (pos[number_in_pos[a] - 1] > pos[number_in_pos[a]]) + (pos[number_in_pos[a]] > pos[number_in_pos[a] + 1]) + (pos[number_in_pos[b]] > pos[number_in_pos[b] + 1]);

            swap(pos[number_in_pos[a]], pos[number_in_pos[b]]);

            ans += (pos[number_in_pos[a] - 1] > pos[number_in_pos[a]]) + (pos[number_in_pos[a]] > pos[number_in_pos[a] + 1]) + (pos[number_in_pos[b]] > pos[number_in_pos[b] + 1]);
            swap(number_in_pos[a], number_in_pos[b]);
        }

        /* for (int i = 1; i <= n; i++) { */
        /*     cout << number_in_pos[i] << ' '; */
        /* } */
        /* cout << '\n'; */
        /* for (int i = 1; i <= n; i++) { */
        /*     cout << pos[i] << ' '; */
        /* } */
        /* cout << '\n'; */

        cout << ans << '\n';
    }

    return 0;
}
