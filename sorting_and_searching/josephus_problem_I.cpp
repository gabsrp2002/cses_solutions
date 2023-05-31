#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
deque<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        q.push_back(i);
    }

    while (!q.empty()) {
        int holder = q.front();
        q.pop_front();
        q.push_back(holder);
        int curr = q.front();
        q.pop_front();
        cout << curr << ' ';
    }
    cout << '\n';
    return 0;
}
