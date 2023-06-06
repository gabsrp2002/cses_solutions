#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << endl
#define ll long long

int n, k;
int x[200005];

bool check(ll m) {
    int i = 0, j = 0;

    ll curr_sum = 0;
    int counter = 0;
    while (i < n) {
        if (j < n && curr_sum + x[j] <= m) {
            curr_sum += x[j];
            j++;
        } else {
            i = j;
            curr_sum = 0;
            counter++;
            if (counter > k) break;
        }
    }

    return (counter <= k);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        total += x[i];
    }

    ll start = 0, end = total;
    while (start + 1 != end) {
        ll mid = (start + end) / 2;
        if (check(mid))
            end = mid;
        else
            start = mid;
    }

    cout << end << '\n';

    return 0;
}
