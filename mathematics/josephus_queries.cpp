#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int q, n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        auto it = s.begin();
        n--;
        while (n--) {
            it++;
            if (it == s.end()) it = s.begin();
            cout << *it << '\n';
            it = s.erase(it);
            if (it == s.end()) it = s.begin();
        }
        it++;
        if (it == s.end()) it = s.begin();
        cout << *it << '\n';
    }

    return 0;
}
