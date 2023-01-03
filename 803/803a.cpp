#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        if (k == 0) break;
        v[i][i] = 1;
        k--;
        for (int j = i+1; j < n; ++j) {
            if (k <= 1) break;
            v[j][i] = 1;
            v[i][j] = 1;
            k -= 2;
        }
    }
    if (k > 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
}