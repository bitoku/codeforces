#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> result(n);
    ll x = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            x = 0;
        }
        result[i] = x;
        x++;
    }
    x = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0) {
            x = 0;
        }
        result[i] = min(result[i], x);
        x++;
    }
    for (auto k: result) {
        cout << k << ' ';
    }
    cout << endl;
}