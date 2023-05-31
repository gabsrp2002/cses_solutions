#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';

        return 0;
    }
    if (n < 4) {
        cout << "NO SOLUTION" << '\n';

        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            cout << (i + 1) / 2 << ' ';
        } else {
            cout << (n / 2) + (i / 2) + 1 << ' ';
        }
    }

    return 0;
}
