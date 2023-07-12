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
    while (pi[n - 1] != 0) {
        ans.push_back(pi[n - 1]);
        n = pi[n - 1];
    }
    reverse(ans.begin(), ans.end());
    for (auto item : ans) {
        cout << item << ' ';
    }
    cout << '\n';

    return 0;
}
