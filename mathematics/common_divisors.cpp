#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int in_array[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        in_array[tmp]++;
    }

    for (int i = 1000000; i >= 1; i--) {
        int number_of_multiples = 0;
        for (int j = 1; 1ll * j * i <= 1000000; j++) {
            if (in_array[j * i]) number_of_multiples += in_array[j * i];

            if (number_of_multiples >= 2) {
                cout << i << '\n';
                return 0;
            }
        }
    }
    return 0;
}
