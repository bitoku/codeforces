#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    ll m = n / (a * b / gcd(a, b));
    ll k = n / a - m;
    ll l = n / b - m;
    ll result = 0;
    if (p < q) {
        result = m * q;
    } else {
        result = m * p;
    }
    result += k * p + l * q;
    cout << result << endl;
}