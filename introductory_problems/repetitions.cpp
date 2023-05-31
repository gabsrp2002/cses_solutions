#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int ans;

    cin >> s;

    int i = 0;
    int n = s.size();
    ans = 1;
    while (i < n) {
        int counter;
        counter = 1;
        while (s[i] == s[i + 1]) {
            counter++;
            i++;
            if (i == n - 1) break;
        }
        i++;
        ans = max(ans, counter);
    }

    cout << ans << '\n';

    return 0;
}
