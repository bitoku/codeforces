#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n, m;
        cin >> n >> m;
        vector<ll> a(n);
        vector<char> c(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int j = 0; j < n; ++j) {
            cin >> c[j];
        }
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&a](int i, int j) {return a[i] < a[j];});
        deque<int> re, ro, le, lo;
        vector<ll> result(n);
        for (auto j: idx) {
            if (c[j] == 'R' && a[j] % 2 == 0) re.push_back(j);
            if (c[j] == 'R' && a[j] % 2 == 1) ro.push_back(j);
            if (c[j] == 'L' && a[j] % 2 == 0) {
                if (!re.empty()) {
                    result[re.back()] = (a[j] - a[re.back()]) / 2;
                    result[j] = result[re.back()];
                    re.pop_back();
                }
                else le.push_back(j);
            }
            if (c[j] == 'L' && a[j] % 2 == 1) {
                if (!ro.empty()) {
                    result[ro.back()] = (a[j] - a[ro.back()]) / 2;
                    result[j] = result[ro.back()];
                    ro.pop_back();
                }
                else lo.push_back(j);
            }
        }
        while (re.size() > 1) {
            ll j = re.size() - 1, k = re.size() - 2;
            ll diff = (2 * m - a[re[j]] - a[re[k]]) / 2;
            result[re[j]] = diff;
            result[re[k]] = diff;
            re.pop_back();
            re.pop_back();
        }
        while (ro.size() > 1) {
            ll j = ro.size() - 1, k = ro.size() - 2;
            ll diff = (2 * m - a[ro[j]] - a[ro[k]]) / 2;
            result[ro[j]] = diff;
            result[ro[k]] = diff;
            ro.pop_back();
            ro.pop_back();
        }
        while (le.size() > 1) {
            ll j = 0, k = 1;
            ll diff = (a[le[j]] + a[le[k]]) / 2;
            result[le[j]] = diff;
            result[le[k]] = diff;
            le.pop_front();
            le.pop_front();
        }
        while (lo.size() > 1) {
            ll j = 0, k = 1;
            ll diff = (a[lo[j]] + a[lo[k]]) / 2;
            result[lo[j]] = diff;
            result[lo[k]] = diff;
            lo.pop_front();
            lo.pop_front();
        }
        while (!re.empty() && !le.empty()) {
            ll diff = (2 * m - a[re.back()] + a[le.front()]) / 2;
            result[re.back()] = diff;
            result[le.front()] = diff;
            re.pop_back();
            le.pop_front();
        }
        while (!ro.empty() && !lo.empty()) {
            ll diff = (2 * m - a[ro.back()] + a[lo.front()]) / 2;
            result[ro.back()] = diff;
            result[lo.front()] = diff;
            ro.pop_back();
            lo.pop_front();
        }
        if (result[0] == 0) {
            cout << -1;
        } else {
            cout << result[0];
        }
        for (int j = 1; j < n; ++j) {
            if (result[j] == 0) {
                cout << ' ' << -1;
            } else {
                cout << ' ' << result[j];
            }
        }
        cout << endl;
    }
}