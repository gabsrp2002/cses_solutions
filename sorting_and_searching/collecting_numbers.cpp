#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, tmp;
int pos[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        pos[tmp] = i;
    }

    int ans = 1;

    for (int i = 1; i < n; i++) {
        ans += (pos[i] > pos[i + 1]);
    }

    cout << ans << '\n';

    return 0;
}
