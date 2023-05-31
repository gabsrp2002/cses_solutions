#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, m, k;
int a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;    

    int res = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a, a + n);
    sort(b, b + m);

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] < b[j] - k) {
            i++;
        } else if (a[i] > b[j] + k) {
            j++;
        } else {
            res++;
            i++;
            j++;
        }
    }

    cout << res << '\n';

    return 0;
}
