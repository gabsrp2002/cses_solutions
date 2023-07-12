#include <bits/stdc++.h>

using namespace std;

#define dbg(x) cout << #x << " = " << x << endl
typedef long long ll;
const int mod = 1e9 + 7;

int n;
string s;
int pi[1000005];

void kmp() {
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j != 0 && s[i] != s[j]) j = pi[j - 1];

        if (s[i] == s[j]) j++;

        pi[i] = j;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    kmp();

    vector<int> ans;
    int curr = n;
    while (pi[curr - 1] != 0) {
        cout << n - pi[curr - 1] << ' ';
        curr = pi[curr - 1];
    }
    cout << n << '\n';

    return 0;
}
