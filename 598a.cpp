#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n;
        cin >> n;
        ll d = 0;
        ll k = n;
        while (k > 0) {
            k >>= 1;
            d++;
        }
        cout << (1 + n) * n / 2 - 2 * ((1ll << d) - 1) << endl;
    }
}