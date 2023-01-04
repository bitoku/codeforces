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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll s = 0;
    ll ss = 0;
    for (int i = 0; i < k; ++i) {
        s += a[i];
    }
    ss += s;
    for (int i = k; i < n; ++i) {
        s -= a[i - k];
        s += a[i];
        ss += s;
    }
    ld num_weeks = n - k + 1;
    cout << setprecision(20) << ss / num_weeks << endl;
}