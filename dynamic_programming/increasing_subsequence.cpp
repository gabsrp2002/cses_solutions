#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;
const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<int> buckets;
    buckets.push_back(x[0]);

    for (int i = 1; i < n; i++) {
        auto it = lower_bound(buckets.begin(), buckets.end(), x[i]);
        if (it == buckets.end()) {
            buckets.push_back(x[i]);
        } else {
            buckets[it - buckets.begin()] = x[i];
        }
    }

    cout << buckets.size() << '\n';

    return 0;
}
