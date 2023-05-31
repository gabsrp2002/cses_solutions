#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
vector<pair<pair<int, int>, int> >  intervals;
set<pair<int, int> > upper;
int ans[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({{a, b}, i});
    }
    sort(intervals.begin(), intervals.end());

    for (auto p : intervals) {
        auto it = upper.lower_bound({p.first.first, 0});
        if (it == upper.begin()) {
            ans[p.second] = upper.size() + 1;
            upper.insert({p.first.second, upper.size() + 1});
        } else {
            it--;
            ans[p.second] = it->second;
            pair<int, int> new_bound = {p.first.second, it->second};
            upper.erase(it);
            upper.insert(new_bound);
        }
    }

    cout << upper.size() << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
