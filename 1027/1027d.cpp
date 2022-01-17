#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 998244353;

template< typename T >
T mod_pow(T x, T n) {
    T ret = 1;
    while(n > 0) {
        if(n & 1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

unordered_map<ll, ll> fact_memo;
ll mod_fact(ll x) {
    if (fact_memo.find(x) != fact_memo.end()) return fact_memo[x];
    if (x == 0) return 1;
    fact_memo[x] = x * mod_fact(x - 1) % mod;
    return fact_memo[x];
}

unordered_map<ll, ll> invfact_memo;
ll mod_invfact(ll x) {
    if (invfact_memo.find(x) != invfact_memo.end()) return invfact_memo[x];
    invfact_memo[x] = mod_pow(mod_fact(x), mod - 2);
    return invfact_memo[x];
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n; ++i) {
        mod_fact(i);
    }
    pair<ll, ll> p = {-1, -1};
    int x = 0;
    ll dub = 1;
    for (int i = 0; i < n; ++i) {
        if (p == v[i]) {
            x++;
        } else {
            dub *= mod_fact(x);
            dub %= mod;
            x = 1;
        }
        p = v[i];
    }
    dub *= mod_fact(x);
    dub %= mod;

    bool ok = true;
    p = {-1, -1};
    for (int i = 0; i < n; ++i) {
        ok &= p.first <= v[i].first && p.second <= v[i].second;
        p = v[i];
    }
    ll cnt12 = 0;
    if (ok) cnt12 = 1;

    unordered_map<ll, ll> mp;
    for (int i = 0; i < n; ++i) {
        mp[v[i].first]++;
    }

    ll cnt1 = 1;
    for (auto [k, x]: mp) {
        cnt1 *= mod_fact(x);
        cnt1 %= mod;
    }

    mp.clear();
    for (int i = 0; i < n; ++i) {
        mp[v[i].second]++;
    }

    ll cnt2 = 1;
    for (auto [k, x]: mp) {
        cnt2 *= mod_fact(x);
        cnt2 %= mod;
    }

    cout << (mod_fact(n) - cnt1 - cnt2 + dub * cnt12 % mod + 2 * mod) % mod << endl;
}