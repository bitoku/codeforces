#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        vector<ll> a(2 * n);
        ll amari[2] = {};
        for (int j = 0; j < 2 * n; ++j) {
            cin >> a[j];
            amari[a[j] % 2]++;
        }
        if (amari[0] == amari[1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}