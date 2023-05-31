#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, t;
int k[200005];

bool works(ll time) {
    ll total_products = 0;
    for (int i = 0; i < n; i++) {
        total_products += time / k[i]; 
        if (total_products >= t) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    ll start = 0, end = 1e18;

    while (start + 1 != end) {
        ll mid = (start + end) / 2;
        if (works(mid))
            end = mid;
        else
            start = mid;
    }

    cout << end << '\n';

    return 0;
}
