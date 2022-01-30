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
    vector<int> a(n);
    vector<int> b(m+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= m) {
            b[a[i]]++;
        }
    }
    vector<int> c(m+1);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j*i <= m; ++j) {
            c[j*i] += b[i];
        }
    }
    int l = 1;
    int k = 0;
    for (int i = 1; i <= m; ++i) {
        if (c[i] > k) {
            k = c[i];
            l = i;
        }
    }
    cout << l << ' ' << k << '\n';
    for (int i = 0; i < n; ++i) {
        if (l % a[i] == 0) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}