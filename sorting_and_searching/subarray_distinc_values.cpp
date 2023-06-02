#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;        
    set<int> curr_nums;
    unordered_map<int, int> counters;

    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int i = 0, j = 0;
    ll ans = 0;
    while (i < n) {
        while (j < n) {
            curr_nums.insert(x[j]);
            counters[x[j]]++;
            if (curr_nums.size() > k) {
                curr_nums.erase(x[j]);
                counters[x[j]]--;
                break;
            }
            j++;
        }
        ans += j - i;
        counters[x[i]]--;
        if (!counters[x[i]]) curr_nums.erase(x[i]);
        i++;
    }

    cout << ans << '\n';

    return 0;
}
