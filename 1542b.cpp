#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll a, b, n;
        cin >> n >> a >> b;
        ll x = 1;
        bool ok = false;
        if (a != 1) {
            while (x <= n) {
                if ((n - x) % b == 0) {
                    ok = true;
                    break;
                }
                x *= a;
            }
        } else {
            if ((n - 1) % b == 0) {
                ok = true;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}