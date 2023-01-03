#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, k;
    cin >> n >> k;
    if (k >= 1000000) {
        cout << -1 << endl;
        return 0;
    }
    ll x = k * (k + 1) / 2;
    if (n < x) {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> div;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        div.push_back(i);
        if (i * i != n) {
            div.push_back(n / i);
        }
    }
    sort(div.begin(), div.end());
    ll t = 0;
    for (auto d: div) {
        if (n < d * x) break;
        t = d;
//        cout << t << endl;
    }
    for (int i = 0; i < k - 1; ++i) {
        cout << (i + 1) * t << ' ';
    }
    cout << n - (k - 1) * k / 2 * t << endl;
}