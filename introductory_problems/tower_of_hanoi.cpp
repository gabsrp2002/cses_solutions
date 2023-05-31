#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

vector<pair<int, int>> moves;

void hanoi(int begin, int helper, int end, int n) {
    if (n == 0) return;
    hanoi(begin, end, helper, n - 1);
    moves.push_back({begin, end});
    hanoi(helper, begin, end, n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    int n;
    cin >> n;
    hanoi(1, 2, 3, n);

    cout << moves.size() << '\n';

    for (auto p : moves) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
