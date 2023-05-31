#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

string s;
int occurrences[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        occurrences[s[i] - 'A']++;
    }

    int counter = 0;
    int item = -1;
    for (int i = 0; i < 26; i++) {
        if (occurrences[i] & 1) {
            counter++;
            item = i;
            if (counter == 2) {
                cout << "NO SOLUTION" << '\n';
                return 0;
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < occurrences[i] / 2; j++) {
            cout << (char) (i + 'A');
        }
    }
    if (counter) cout << (char) (item + 'A');
    for (int i = 25; i >= 0; i--) {
        for (int j = 0; j < occurrences[i] / 2; j++) {
            cout << (char) (i + 'A');
        }
    }

    return 0;
}
