#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n, m;
int seg[800005];
int h[200005];

void build(int node, int start, int end) {
    if (start == end) {
        seg[node] = h[start];
        return;
    }

    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
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

    seg[node] = max(seg[2 * node], seg[2 * node + 1]);
}

int query(int node, int start, int end, int i, int j) {
    if (i <= start && j >= end) return seg[node];
    if (j < start || i > end) return 0;

    int mid = (start + end) / 2;
    return max(query(2 * node, start, mid, i, j),
               query(2 * node + 1, mid + 1, end, i, j));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    build(1, 0, n - 1);

    while (m--) {
        int r;
        cin >> r;

        if (query(1, 0, n - 1, 0, n - 1) < r) {
            cout << 0 << ' ';
            continue;
        }

        int start = 0, end = n - 1;
        while (start != end) {
            int mid = (start + end) / 2;
            if (query(1, 0, n - 1, start, mid) >= r) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        update(1, 0, n - 1, start, h[start] - r);
        h[start] -= r;

        cout << start + 1 << ' ';
    }

    return 0;
}
