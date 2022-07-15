#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int r = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (a[i] > b[j] && j < m) {
            j++;
        }
        if (j > 0) j--;
        if (a[i] < b[j]) {
            r = max(b[j] - a[i], r);
        } else {
            if (j + 1 < m) {
                r = max(r, min(a[i] - b[j], b[j+1] - a[i]));
            } else {
                r = max(r, a[i] - b[j]);
            }
        }
    }
    cout << r << endl;
}