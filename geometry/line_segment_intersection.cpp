#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

ll X1, Y1, X2, Y2, X3, Y3, X4, Y4;
ll det1, det2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    int cases;
    cin >> cases;
    while (cases--) {
        cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3 >> X4 >> Y4;

        det1 = (X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1);
        det2 = (X2 - X1) * (Y4 - Y1) - (X4 - X1) * (Y2 - Y1);
        if ((det1 > 0 && det2 > 0) || (det1 < 0 && det2 < 0)) {
            cout << "NO" << '\n';
            continue;
        }

        if (!det1 && !det2) {
            if (((max(X3, X4) >= X1 && min(X3, X4) <= X1) &&
                 (max(Y3, Y4) >= Y1 && min(Y3, Y4) <= Y1)) ||
                ((max(X3, X4) >= X2 && min(X3, X4) <= X2) &&
                 (max(Y3, Y4) >= Y2 && min(Y3, Y4) <= Y2)) ||
                ((max(X1, X2) >= X3 && min(X1, X2) <= X3) &&
                 (max(Y1, Y2) >= Y3 && min(Y1, Y2) <= Y3)) ||
                ((max(X1, X2) >= X4 && min(X1, X2) <= X4) &&
                 (max(Y1, Y2) >= Y4 && min(Y1, Y2) <= Y4))) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }

        if (!det1) {
            if (max(X1, X2) >= X3 && min(X1, X2) <= X3 && max(Y1, Y2) >= Y3 && min(Y1, Y2) <= Y3) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }
        if (!det2) {
            if (max(X1, X2) >= X4 && min(X1, X2) <= X4 && max(Y1, Y2) >= Y4 && min(Y1, Y2) <= Y4) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
            continue;
        }

        det1 = (X4 - X3) * (Y1 - Y3) - (X1 - X3) * (Y4 - Y3);
        det2 = (X4 - X3) * (Y2 - Y3) - (X2 - X3) * (Y4 - Y3);
        if ((det1 > 0 && det2 > 0) || (det1 < 0 && det2 < 0)) {
            cout << "NO" << '\n';
            continue;
        }

        cout << "YES" << '\n';
    }

    return 0;
}
