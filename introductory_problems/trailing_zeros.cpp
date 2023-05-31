#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

int n, tmp, ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    tmp = n;

    while (tmp) {
        ans += tmp % 5;
        tmp /= 5;
    }

    ans = (n - ans) / 4;

    cout << ans << '\n';

    return 0;
}
