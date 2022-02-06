#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n, x, y;
        cin >> n >> x >> y;
        vector<ll> a(n);
        ll s = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            s ^= a[i];
        }
        if ((y & 1) == (x & 1)) {
            if (s & 1) {
                cout << "Bob" << '\n';
            } else {
                cout << "Alice" << '\n';
            }
        } else {
            if (s & 1) {
                cout << "Alice" << '\n';
            } else {
                cout << "Bob" << '\n';
            }
        }
    }
}