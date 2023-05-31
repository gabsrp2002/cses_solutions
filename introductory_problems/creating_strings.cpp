#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int frequency[26];
int string_size;
string possible;
vector<string> ans;

void backtrack(int n) {
    if (n == string_size) {
        ans.push_back(possible);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (frequency[i]) {
            frequency[i]--;
            possible[n] = (char)('a' + i);
            backtrack(n + 1);
            frequency[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    string s;
    cin >> s;
    string_size = s.size();

    possible = "";
    for (int i = 0; i < string_size; i++) {
        frequency[s[i] - 'a']++;
        possible += s[i];
    }

    backtrack(0);

    cout << ans.size() << '\n';
    for (string item : ans) {
        cout << item << '\n';
    }
    return 0;
}
