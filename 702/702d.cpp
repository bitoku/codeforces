#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;
    ll x = d / k;
    ll r = d % k;
    ll result = b * d;
    if (r == 0) {
        result = min(result, a * d + (x - 1) * t);
    } else {
        result = min(result, a * d + x * t);
    }
    if (x == 0) {
        cout << result << endl;
        return 0;
    }
    if (a * k - b * k + t > 0) {
        result = min(result, a * k - b * k + b * d);
    } else if (a * k - b * k + t < 0) {
        result = min(result, a * x * k + (x - 1) * t + b * r);
    }
    cout << result << endl;
    return 0;
}