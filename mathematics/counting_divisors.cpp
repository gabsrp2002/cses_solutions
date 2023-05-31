#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

int x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    int cases;
    cin >> cases;
    while (cases--) {
        int divisors = 0;

        cin >> x;

        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) divisors += 2;
            if (i * i == x) divisors--;
        }

        cout << divisors << '\n';
    }

    return 0;
}
