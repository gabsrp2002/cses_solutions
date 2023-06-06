#include <bits/stdc++.h>

#include <vector>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

const int mod = 1e9 + 7;

vector<vector<int>> mult_mat(vector<vector<int>> &m1, vector<vector<int>> &m2) {
    vector<vector<int>> result =
        vector<vector<int>>(m1.size(), vector<int>(m2[0].size()));

    for (int i = 0; i < (int)m1.size(); i++) {
        for (int j = 0; j < (int)m2[0].size(); j++) {
            result[i][j] = 0;
            for (int k = 0; k < (int)m2.size(); k++) {
                result[i][j] = (result[i][j] + 1ll * m1[i][k] * m2[k][j]) % mod;
            }
        }
    }

    return result;
}

vector<vector<int>> exp_mat(vector<vector<int>> &base, ll exp) {
    if (exp == 0) {
        vector<vector<int>> I =
            vector<vector<int>>(base.size(), vector<int>(base.size(), 0));
        for (int i = 0; i < (int)base.size(); i++) {
            I[i][i] = 1;
        }
        return I;
    }

    vector<vector<int>> aux = exp_mat(base, exp / 2);
    aux = mult_mat(aux, aux);

    if (exp & 1) aux = mult_mat(aux, base);

    return aux;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    vector<vector<int>> base(2, vector<int>(2, 1));
    base[1][1] = 0;

    cout << exp_mat(base, n)[0][1] << '\n';

    return 0;
}
