#include <bits/stdc++.h>

#include <algorithm>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int n, x;
vector<int> t;

vector<ll> get_subsets(int start, int end) {
    int l = end - start + 1;

    vector<ll> subsets(0);
    for (int i = 0; i < (1 << l); i++) {
        ll curr_sum = 0;
        for (int j = 0; j < l; j++) {
            if (i & (1 << j)) {
                curr_sum += t[start + j];
            }
        }
        subsets.push_back(curr_sum);
    }

    return subsets;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        t.push_back(tmp);
    }

    vector<ll> left = get_subsets(0, n / 2 - 1);
    vector<ll> right = get_subsets(n / 2, n - 1);

    sort(right.begin(), right.end());

    ll ans = 0;

    for (auto item : left) {
        if (item > x) continue;
        if (item == x) {
            ans++;
            continue;
        }

        int goal = x - item;

        auto it = lower_bound(right.begin(), right.end(), goal);

        if (it == right.end() || *it != goal) continue;

        auto it2 = upper_bound(right.begin(), right.end(), goal);

        ans += it2 - it;
    }

    cout << ans << '\n';

    return 0;
}
