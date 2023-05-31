#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
ll x;
vector<pair<ll, int> > a;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        a.push_back({tmp, i + 1});
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            ll goal = x - a[i].first - a[j].first;
            if (goal <= 0) break;

            int start = j, end = n - 1;
            while (start + 1 != end) {
                int mid = (start + end) / 2;
                if (a[mid].first >= goal)
                    end = mid;
                else
                    start = mid;
            }

            if (a[end].first == goal) {
                cout << a[i].second << ' ' << a[j].second << ' ' << a[end].second << '\n';
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
