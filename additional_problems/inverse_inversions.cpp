#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<int> end, begin;

    for (int i = n; i >= 1; i--) {
        if (k <= 1ll * (i - 1) * (i - 2) / 2) {
            end.push_back(i);
        } else {
            k -= i - 1;
            begin.push_back(i);
        }
    }
    reverse(end.begin(), end.end());

    for (auto item : begin) {
        cout << item << ' ';
    }
    for (auto item : end) {
        cout << item << ' ';
    }
    cout << '\n';

    return 0;
}
