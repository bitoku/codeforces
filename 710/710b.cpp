#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> s(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < n; ++i) {
        s[i+1] = s[i] + x[i];
    }
    ll sum = LONG_LONG_MAX;
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        ll t = (2 * i + 2 - n) * x[i] + s[n] - 2 * s[i+1];
        if (t < sum) {
            result = x[i];
            sum = t;
        }
    }
    cout << result << endl;
}