#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, a, b;
pair<int, int> times[400005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        times[2 * i] = {a, 1};
        times[2 * i + 1] = {b, -1};
    }

    sort(times, times + 2 * n);

    int res = 0;
    int par_sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        par_sum += times[i].second;
        res = max(res, par_sum);
    }

    cout << res << '\n';

    return 0;
}
