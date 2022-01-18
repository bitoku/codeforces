#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, b, p;
    cin >> n >> b >> p;
    ll bottles = 0;
    ll towels = n * p;
    while (n > 1) {
        ll k = 1;
        while (k <= n) {
            k <<= 1;
        }
        k >>= 1;
        ll matches = k >> 1;
        bottles += matches * (2 * b + 1);
        n -= matches;
    }
    cout << bottles << ' ' << towels << endl;
}