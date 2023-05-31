#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll k;
ll sizes[20];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    ll power = 1;

    for (int i = 0; i < 20; i++) {
        sizes[i] = power * 9 * (i + 1);
        power *= 10;
    }

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> k;

        int i;
        for (i = 0; i < 20; i++) {
            if (k > sizes[i]) {
                k -= sizes[i];
            } else {
                break;
            }
        }

        if (i == 0) {
            cout << k << '\n';
            continue;
        }

        power = 1;
        for (int j = 0; j < i; j++) {
            power *= 10;
        }
        i++;
        power += (k - 1) / i;
        k = (k - 1) % i + 1;

        k = i - k;
        while (k--) {
            power /= 10;
        }

        cout << power % 10 << '\n';
    }

    return 0;
}
