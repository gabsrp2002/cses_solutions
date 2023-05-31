#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
        << "\n"
#define ll long long

int n, x;
int p[200005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    int ini = 0, fim = n - 1;
    int res = 0;
    while (ini < fim) {
        if (p[ini] + p[fim] <= x) {
            ini++;
        }
        fim--;
        res++;
    }
    if (ini == fim) res++;

    cout << res << '\n';
    return 0;
}
