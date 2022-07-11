#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll a, b, n, x;
    cin >> a >> b >> n >> x;
    vector<pair<ll, ll>> ab;
    ab.emplace_back(a, b);
    for (int i = 0; (1ll << i) <= n; ++i) {
        auto [aa, bb] = ab.back();
        ab.emplace_back(aa * aa % mod, (aa * bb + bb) % mod);
    }
    for (int i = 0; (1ll << i) <= n; ++i) {
        auto [aa, bb] = ab[i];
        if (n & (1ll << i)) {
            x = aa * x + bb;
            x %= mod;
        }
    }
    cout << x << endl;
}