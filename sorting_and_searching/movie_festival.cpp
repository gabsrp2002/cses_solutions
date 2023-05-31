#include <bits/stdc++.h>

using namespace std;

#define db          \
    cout << "Debug" \
         << "\n"
#define ll long long

int n;
int a, b;
vector<pair<int, int>> movies;
pair<int, int> last_movie;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        movies.push_back({a, b});
    }

    sort(movies.begin(), movies.end());

    last_movie = movies[0];

    int ans = 1;

    for (int i = 1; i < n; i++) {
        auto curr_movie = movies[i];
        if (curr_movie.first >= last_movie.second) {
            ans++;
            last_movie = curr_movie;
        } else {
            if (curr_movie.second < last_movie.second) {
                last_movie = curr_movie;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
