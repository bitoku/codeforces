#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    vector<ll> p = {2, 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19, 23, 25, 27, 29, 31, 32, 37, 41};
    vector<ll> pp = {2, 3, 2, 5, 7, 2, 3, 11, 13, 2, 17, 19, 23, 5, 3, 29, 31, 2, 37};
    deque<ll> pq;
    reverse(p.begin(), p.end());
    pq.push_front(1);
    for (auto x: pp) {
        pq.push_front(x * pq.front());
    }
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        ll k = 0;
        ll result = 0;
        for (int i = 0; i < p.size(); ++i) {
            result += (n / pq[i] - k) % mod * p[i] % mod;
            k = n / pq[i] % mod;
            result %= mod;
        }
        cout << result << endl;
    }
}