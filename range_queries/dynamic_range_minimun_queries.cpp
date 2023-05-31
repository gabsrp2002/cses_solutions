#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, q;
int seg[800005];
int x[200005];

void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = x[start];
        return;
    }

    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

void update(int node, int start, int end, int pos, int val) {
    if (pos < start || pos > end) return;
    if (start == end) {
        seg[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(2 * node, start, mid, pos, val);
    update(2 * node + 1, mid + 1, end, pos, val);

    seg[node] = min(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int start, int end, int i, int j) {
    if (i <= start && j >= end) return seg[node];
    if (j < start || i > end) return 1e9;

    int mid = (start + end) / 2;
    return min(query(2 * node, start, mid, i, j),
               query(2 * node + 1, mid + 1, end, i, j));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    build(1, 0, n - 1);

    while (q--) {
        int option, a, b;
        cin >> option >> a >> b;

        if (option == 1) {
            update(1, 0, n - 1, a - 1, b);
        } else {
            cout << query(1, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }

    return 0;
}
