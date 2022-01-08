#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll n;
    cin >> n;
    vector<ll> m(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        sum += m[i];
    }
    ll r = sum % n;
    ll q = sum / n;
    ll result2 = 0;
    sort(m.begin(), m.end());
    for (int i = 0; i < n - r; ++i) {
        result2 += abs(q - m[i]);
    }
    for (int i = n - r; i < n; ++i) {
        result2 += abs(q + 1 - m[i]);
    }
    cout << result2 / 2 << endl;
}