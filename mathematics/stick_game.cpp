#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, k, p[101], ans[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> p[i];
    }
    sort(p, p + k);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (p[j] > i) break;
            if (!ans[i - p[j]]) ans[i] = 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (ans[i] ? "W" : "L");
    }
    cout << '\n';

    return 0;
}
