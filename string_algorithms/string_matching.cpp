#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
string s1, s2;
int pi[1000005];

void kmp() {
    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];
        while (j != 0 && s2[i] != s2[j]) {
            j = pi[j - 1];
        }

        if (s2[i] == s2[j]) {
            j++;
        }

        pi[i] = j;
    }
}

int count_matches() {
    int j = 0;
    int i = 0;
    int counter = 0;
    while (i != n) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            if (j != 0) {
                j = pi[j - 1];
            } else {
                i++;
            }
        }
        if (j == m) {
            counter++;
            j = pi[j - 1];
        }
    }

    return counter;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();

    kmp();
    cout << count_matches() << '\n';

    return 0;
}
