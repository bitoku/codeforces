#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll k;
        cin >> k;
        if (k == 100) {
            cout << 1 << endl;
            continue;
        }
        ll g = gcd(k, 100-k);
        cout << k / g + (100 - k) / g << endl;
    }
}