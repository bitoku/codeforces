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
    vector<ll> v;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            v.push_back(i);
        }
    }
    if (v.back() * v.back() == n) {
        if (k > v.size() * 2 - 1) {
            cout << -1 << endl;
        } else if (k > v.size()) {
            cout << n / v[2 * v.size() - 1 - k] << endl;
        } else {
            cout << v[k-1] << endl;
        }
    } else {
        if (k > v.size() * 2) {
            cout << -1 << endl;
        } else if (k > v.size()) {
            cout << n / v[2 * v.size() - k] << endl;
        } else {
            cout << v[k-1] << endl;
        }
    }
}