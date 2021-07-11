#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

map<ll, ll> factorize(ll n) {
    map<ll, ll> ret;
    while (n % 2 == 0) {
        n /= 2;
        ret[2]++;
    }
    for (ll i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            n /= i;
            ret[i]++;
        }
    }
    if (n > 1) ret[n]++;
    return ret;
}

template<class T>
T gcd(T a, T b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        map<ll, pair<int, int>> f;
        int result = 0;
        cin >> a[0];
        ll g = a[0];
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            g = gcd(g, a[i]);
        }
        for (int i = 0; i < n; ++i) {
            a[i] /= g;
        }
        map<ll, int> loop;
        for (int i = 1; i <= n; ++i) {
            map<ll, ll> fact = factorize(a[i-1]);
            for (auto [x, _]: fact) {
                if (f.find(x) == f.end()){
                    f[x].first = i;
                    f[x].second = i;
                } else if (f[x].second + 1 != i) {
                    if (f[x].first == 1) loop[x] = f[x].second;
                    f[x].first = i;
                    f[x].second = i;
                } else {
                    f[x].second++;
                }
                result = max(result, f[x].second - f[x].first + 1);
            }
        }
        for (auto [x, p]: f) {
            if (p.second == n) {
                result = max(result, loop[x] + (int)n - p.first + 1);
            }
        }
        cout << result << endl;
    }
}