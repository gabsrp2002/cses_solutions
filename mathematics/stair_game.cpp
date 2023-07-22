#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int nim_counter = 0;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (i & 1) nim_counter ^= tmp;
        }
        cout << (nim_counter ? "first" : "second") << '\n';
    }

    return 0;
}
