#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

const int mod = 1e9 + 7;

int n, k;
string s;
int dp[5005];

struct no {
    no *chars[26];
    int counter;
    no() : chars(), counter(0) {}
    no *init(int index) {
        if (!chars[index]) chars[index] = new no();
        return chars[index];
    }
};

void add(struct no *tree, const string &s) {
    for (auto c : s) {
        tree = tree->init(c - 'a');
    }
    tree->counter++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.size();
    cin >> k;

    auto tree = new no();
    string tmp;
    while (k--) {
        cin >> tmp;
        add(tree, tmp);
    }

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        auto curr = tree;
        for (int j = i; j < n; j++) {
            if (!curr->chars[s[j] - 'a']) break;
            curr = curr->chars[s[j] - 'a'];
            if (curr->counter) dp[j + 1] = (dp[j + 1] + dp[i]) % mod;
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
