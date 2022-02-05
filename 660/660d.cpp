#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

class FenwickTree {
public:
    ll n;
    vector<ll> a;
    explicit FenwickTree(ll _n): n(_n), a(_n+1, 0) {}

    void add(ll i, ll x) {
        i++;
        if (i == 0) return;
        for (ll k = i; k <= n; k+=(k & -k)) {
            a[k] += x;
        }
    }

    ll sum(ll i) {
        i++;
        ll s = 0;
        if (i == 0) return s;
        for (ll k = i; k > 0; k -= (k & -k)) {
            s += a[k];
        }
        return s;
    }
};


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> q(n);
    FenwickTree ft(2 * n);
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        q[i] = {a, b, i};
        mp[a];
        mp[b];
    }
    int t = 0;
    for (auto& [a, k]: mp) {
        k = t;
        t++;
    }
    sort(q.begin(), q.end(), greater());
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        auto [a, b, j] = q[i];
        result[j] = ft.sum(mp[b]);
        ft.add(mp[b], 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << '\n';
    }
    cout << endl;
}