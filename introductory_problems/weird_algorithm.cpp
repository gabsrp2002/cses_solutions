#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    while (true) {
        cout << n << ' ';

        if (n == 1) break;

        if (n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }

    cout << '\n';
    return 0;
}
