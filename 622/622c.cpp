#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

template<class Condition>
ll binsearch(ll ng, ll ok, Condition func) {
    while (abs(ok - ng) > 1) {
        ll mid = (ng + ok) / 2;
        if (func(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<vector<int>> x(1000001);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        x[a[i]].push_back(i+1);
    }
    for (auto & v : x) {
        sort(v.begin(), v.end());
    }
    for (int i = 0; i < m; ++i) {
        int l, r, p;
        cin >> l >> r >> p;
        auto& v = x[p];
        auto it = lower_bound(v.begin(), v.end(), l);
        if (it == v.end() || *it != l) {
            cout << l << '\n';
            continue;
        }
        auto itr = lower_bound(v.begin(), v.end(), r);
        if (it == v.end() || *itr != r) {
            cout << r << '\n';
            continue;
        }
        if (distance(it, itr) == r - l) {
            cout << -1 << '\n';
            continue;
        }
        int il = (int)distance(v.begin(), it);
        int ok = il, ng = (int)distance(v.begin(), itr);
        while (abs(ok - ng) > 1) {
            int mid = (ng + ok) / 2;
            if (v[mid] == *it + mid - il) ok = mid;
            else ng = mid;
        }
        cout << v[ok] + 1 << '\n';
    }
}