#include<bits/stdc++.h>

using namespace std;

#define db cout << "Debug" << "\n"
#define ll long long

int n;
vector<string> gray_code;

void fill(int n) {
    if (n == 1) {
        gray_code.push_back("0");
        gray_code.push_back("1");
        return;
    }
    fill(n - 1);
    for (int i = (1 << (n - 1)) - 1; i >= 0; i--) {
        gray_code.push_back(gray_code[i] + "1");
        gray_code[i] += "0";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision();
    cout.setf(ios::fixed);

    cin >> n;    

    fill(n);

    for (string s : gray_code) {
        cout << s << '\n';
    }

    return 0;
}
