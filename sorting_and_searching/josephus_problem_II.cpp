#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, k;
indexed_set q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        q.insert(i);
    }

    int curr;

    curr = k % n;
    while (n--) {
        auto ans = q.find_by_order(curr);
        cout << *ans << ' ';
        q.erase(ans);

        if (n) curr = (curr + k) % n;
    }
    cout << '\n';
    return 0;
}
