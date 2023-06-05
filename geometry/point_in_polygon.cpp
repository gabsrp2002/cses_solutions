#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
typedef long long ll;

const ll INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > points(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }

    while (m--) {
        int x, y;
        cin >> x >> y;
        int counter = 0;
        set<int> directions;
        for (int i = 1; i <= n + 1; i++) {
            directions.insert(i);
        }
        for (int i = 0; i < n; i++) {
            if (points[i].first == x) continue;
            int div = (points[i].second - y) / (points[i].first - x);
            directions.erase(div);
        }
        int direction = *directions.begin();
        for (int i = 0; i < n; i++) {
            ll X1, Y1, X2, Y2, X3, Y3, X4, Y4;
            X1 = points[i].first, Y1 = points[i].second;
            X2 = points[(i + 1) % n].first, Y2 = points[(i + 1) % n].second;
            X3 = x, Y3 = y;
            X4 = x + (INF / direction), Y4 = y + (INF / direction) * direction;

            ll det = (X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1);

            if (det == 0) {
                if (X3 <= max(X2, X1) && X3 >= min(X1, X2) &&
                    Y3 <= max(Y1, Y2) && Y3 >= min(Y1, Y2)) {
                    cout << "BOUNDARY" << '\n';
                    counter = -1;
                    break;
                }
            }

            ll det1 = (X2 - X1) * (Y3 - Y1) - (X3 - X1) * (Y2 - Y1);
            ll det2 = (X2 - X1) * (Y4 - Y1) - (X4 - X1) * (Y2 - Y1);
            if ((det1 > 0 && det2 > 0) || (det1 < 0 && det2 < 0)) {
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
                    counter++;
                }
                continue;
            }

            if (!det1) {
                if (max(X1, X2) >= X3 && min(X1, X2) <= X3 &&
                    max(Y1, Y2) >= Y3 && min(Y1, Y2) <= Y3) {
                    counter++;
                }
                continue;
            }
            if (!det2) {
                if (max(X1, X2) >= X4 && min(X1, X2) <= X4 &&
                    max(Y1, Y2) >= Y4 && min(Y1, Y2) <= Y4) {
                    counter++;
                }
                continue;
            }

            det1 = (X4 - X3) * (Y1 - Y3) - (X1 - X3) * (Y4 - Y3);
            det2 = (X4 - X3) * (Y2 - Y3) - (X2 - X3) * (Y4 - Y3);
            if ((det1 > 0 && det2 > 0) || (det1 < 0 && det2 < 0)) {
                continue;
            }

            counter++;
        }

        if (counter == -1) continue;

        cout << ((counter & 1) ? "INSIDE" : "OUTSIDE") << '\n';
    }

    return 0;
}
