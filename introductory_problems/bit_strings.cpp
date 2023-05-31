#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long
const int mod = 1000000007;

int n, ans;

int pot(int n) {
    if (n == 0) return 1;
    int aux = pot(n / 2);

    if (n & 1) return (1ll * aux * aux * 2) % mod;

    return (1ll * aux * aux) % mod;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;

    cout << pot(n) << '\n';
    return 0;
}
