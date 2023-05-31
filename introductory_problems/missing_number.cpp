#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

ll a, s;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    s = (1ll * n * (n + 1)) / 2;

    for (int i = 1; i < n; i++) {
        cin >> a;

        s -= a;
    }

    cout << s << '\n';

    return 0;
}
