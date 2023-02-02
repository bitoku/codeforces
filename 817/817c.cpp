#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, s;
    cin >> n >> s;
    int t = 0;
    ll k = n;
    while (k > 0) {
        t += 9;
        k /= 10;
    }
    ll l = min(s + t, n);
    ll result = n - l;
    for (ll i = s; i <= l; ++i) {
        int d = 0;
        ll x = i;
        while (x > 0) {
            d += x % 10;
            x /= 10;
        }
        if (i - d >= s) {
            result++;
        }
    }
    cout << result << endl;
}
