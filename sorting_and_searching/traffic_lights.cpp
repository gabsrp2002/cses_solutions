#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int x, n, p;
set<int> lights;
multiset<int> dist;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> n;
    
    lights.insert(0);
    lights.insert(x);
    dist.insert(x);

    while (n--) {
        cin >> p;
        lights.insert(p);
        auto it = lights.find(p);
        it++;
        auto up = it;
        it--;
        it--;
        auto low = it;
        dist.erase(dist.find(*up - *low));
        dist.insert(*up - p);
        dist.insert(p - *low);

        auto max_it = dist.end();
        max_it--;

        cout << *max_it << '\n';
    }

    return 0;
}
