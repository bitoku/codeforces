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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    ll result = 0;
    ll odd_plus = INT_MAX;
    ll odd_minus = INT_MIN;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            result += a[i];
        }
        if (a[i] > 0 && a[i] % 2 != 0) {
            odd_plus = min(odd_plus, a[i]);
        } else if (a[i] % 2 != 0) {
            odd_minus = max(odd_minus, a[i]);
            if (odd_minus != INT_MIN) break;
        }
    }
    if (result % 2 != 1) {
        if (odd_plus != INT_MAX && odd_minus != INT_MIN) {
            result = max(result - odd_plus, result + odd_minus);
        } else if (odd_plus != INT_MAX) {
            result = result - odd_plus;
        } else {
            result = result + odd_minus;
        }
    }
    cout << result << endl;
}