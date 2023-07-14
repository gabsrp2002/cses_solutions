#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, n;
    cin >> x >> n;
    ll ans = 0;
    multiset<int> lenghts;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        lenghts.insert(tmp);
    }

    while (lenghts.size() > 1) {
        int val1 = *lenghts.begin();
        lenghts.erase(lenghts.begin());
        int val2 = *lenghts.begin();
        lenghts.erase(lenghts.begin());
        ans += val1 + val2;
        lenghts.insert(val1 + val2);
    }

    cout << ans << '\n';

    return 0;
}
