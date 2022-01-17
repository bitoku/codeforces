#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<ll> b(n);
        b[0] = a[0];
        for (int i = 1; i < n; ++i) {
            b[i] = b[i-1] | a[i];
        }
        for (int i = 0; i < n; ++i) {
            b[i] ^= a[i];
        }
        cout << b[0];
        for (int i = 1; i < n; ++i) {
            cout << ' ' << b[i];
        }
        cout << endl;
    }
}