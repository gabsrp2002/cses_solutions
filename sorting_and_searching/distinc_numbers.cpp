#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, x;
set<int> numbers;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        numbers.insert(x);
    }

    cout << numbers.size() << '\n';

    return 0;
}
