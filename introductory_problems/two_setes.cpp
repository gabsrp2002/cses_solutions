#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

int n;
ll s;
vector<int> set1, set2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    s = (1ll * n * (n + 1)) / 2;

    if (s & 1) {
        cout << "NO" << '\n';

        return 0;
    }

    s /= 2;

    for (int i = n; i; i--) {
        if (s >= i) {
            s -= i;
            set1.push_back(i);
        }
        else {
            set2.push_back(i);
        }
    }

    if (s != 0) {
        cout << "NO" << '\n';

        return 0;
    }

    cout << "YES" << '\n';

    cout << set1.size() << '\n';
    for (int item : set1) {
        cout << item << ' ';
    }
    cout << '\n';

    cout << set2.size() << '\n';
    for (int item : set2) {
        cout << item << ' ';
    }
    cout << '\n';
    return 0;
}
