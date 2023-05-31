#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

char board[8][9];
int columns[8], diagonals[15], ldiagonals[15];
int total;

void backtrack(int row) {
    if (row == 8) {
        total++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (board[row][i] == '*') continue;
        if (columns[i] || diagonals[i + row] ||
            ldiagonals[i - row + 7])
            continue;

        columns[i] = 1, diagonals[i + row] = 1,
        ldiagonals[i - row + 7] = 1;

        backtrack(row + 1);

        columns[i] = 0, diagonals[i + row] = 0,
        ldiagonals[i - row + 7] = 0;
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%8s", board[i]);
    }

    backtrack(0);

    printf("%d\n", total);

    return 0;
}
