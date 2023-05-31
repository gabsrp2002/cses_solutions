#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll X1, Y1, X2, Y2, X3, Y3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;

        ll det = (X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1);

        if (det < 0) {
            cout << "RIGHT" << '\n';
        } else if (det > 0) {
            cout << "LEFT" << '\n';
        } else {
            cout << "TOUCH" << '\n';
        }
    }

    return 0;
}
