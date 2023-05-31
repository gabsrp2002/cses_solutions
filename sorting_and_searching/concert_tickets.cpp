#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
int t[200005];
multiset<int> h;
int tmp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        h.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < m; i++) {
        auto it = h.upper_bound(t[i]);
        if (it == h.begin()) {
            t[i] = -1;
            continue;
        }

        it--;
        t[i] = *it;
        h.erase(it);
    }

    for (int i = 0; i < m; i++) {
        cout << t[i] << '\n';
    }
    return 0;
}
