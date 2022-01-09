#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
pair<ll, ll> binsearch(ll ng, ll ok, Condition func) {
    ll result = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        auto [cond, x] = func(mid);
        if (cond) {
            ok = mid;
            result = x;
        }
        else ng = mid;
    }
    return make_pair(ok, result);
}

int main() {
    ll n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<ll> a(n), b(n);
    vector<pair<ll, int>> ma(n + 2), mb(n + 2);
    ma[0] = {INT_MAX, 0};
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < ma[i].first) {
            ma[i+1].first = a[i];
            ma[i+1].second = i + 1;
        } else {
            ma[i+1] = ma[i];
        }
    }
    ma[n+1] = {0, 0};
    mb[0] = {INT_MAX, 0};
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] < mb[i].first) {
            mb[i+1].first = b[i];
            mb[i+1].second = i + 1;
        } else {
            mb[i+1] = mb[i];
        }
    }
    mb[n+1] = {0, 0};
    vector<pair<ll, int>> dollar, pound;
    for (int i = 0; i < m; ++i) {
        int t;
        ll c;
        cin >> t >> c;
        if (t == 1) dollar.emplace_back(c, i + 1);
        else pound.emplace_back(c, i + 1);
    }
    sort(dollar.begin(), dollar.end());
    sort(pound.begin(), pound.end());
    auto func = [&](ll x) {
        ll dd = ma[x].first, pp = mb[x].first;
        vector<ll> ddd(dollar.size() + 1), ppp(pound.size() + 1);
        for (int i = 0; i < dollar.size(); ++i) {
            ddd[i+1] = ddd[i] + dollar[i].first * dd;
        }
        for (int i = 0; i < pound.size(); ++i) {
            ppp[i+1] = ppp[i] + pound[i].first * pp;
        }
        for (int i = max(0ll, k - (ll)pound.size()); i <= min(k, (ll)dollar.size()); ++i) {
            if (ddd[i] + ppp[k - i] <= s) {
                return make_pair(true, i);
            }
        }
        return make_pair(false, 0);
    };
    auto [x, t] = binsearch(0, n+1, func);
    if (x == n + 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << x << endl;
    for (int i = 0; i < t; ++i) {
        cout << dollar[i].second << ' ' << ma[x].second << endl;
    }
    for (int i = 0; i < k - t; ++i) {
        cout << pound[i].second << ' ' << mb[x].second << endl;
    }
}