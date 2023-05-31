#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
int x[200005], ans[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;    
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 1; i < n; i++) {
        int curr = i - 1;
        while (x[curr] >= x[i]) {
            if (ans[curr] == 0) {
                break;
            }
            curr = ans[curr] - 1;
        }

        if (x[curr] >= x[i]) {
            ans[i] = 0;
            continue;
        }
        ans[i] = curr + 1;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
