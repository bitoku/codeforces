#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            a[i][j] = x;
        }
    }
    vector<pair<int, int>> result;
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < m-1; ++j) {
            if (a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) {
                result.emplace_back(i+1, j+1);
            }
        }
    }
    for (auto [i, j]: result) {
        a[i-1][j-1] = false;
        a[i][j-1] = false;
        a[i-1][j] = false;
        a[i][j] = false;
    }
    bool ng = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            ng |= a[i][j];
        }
    }
    if (ng) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        for (auto [i, j]: result) {
            cout << i << ' ' << j << endl;
        }
    }
}