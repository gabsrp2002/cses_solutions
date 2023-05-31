#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, k;
multiset<int> tops;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> k;
    tops.insert(k);

    for (int i = 1; i < n; i++) {
        cin >> k;
        auto it = tops.upper_bound(k);
        if (it == tops.end()) {
            tops.insert(k);
        } else {
            tops.erase(it);
            tops.insert(k);
        }
        /* for (auto item : tops) { */
        /*     cout << item << ' '; */
        /* } */
        /* cout << '\n'; */
    }

    cout << tops.size() << '\n';

    return 0;
}
