#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

const int mod = 1e9 + 7;

int n, x;
int c[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;    
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c, c + n);



    return 0;
}
