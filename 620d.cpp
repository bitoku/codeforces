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
    ll sa = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sa += a[i];
    }
    vector<pair<ll, pair<int, int>>> va;
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            va.emplace_back(a[i] + a[j], make_pair(i+1, j+1));
        }
    }
    int m;
    cin >> m;
    vector<ll> b(m);
    ll sb = 0;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sb += b[i];
    }
    vector<pair<ll, pair<int, int>>> vb;
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            vb.emplace_back(b[i] + b[j], make_pair(i+1, j+1));
        }
    }
    bool swapped = false;
    if (sa < sb) {
        swap(a, b);
        swap(va, vb);
        swap(sa, sb);
        swap(n, m);
        swapped = true;
    }
    ll x = sa - sb;
    ll result = x;
    pair<int, int> sw1 = {-1, -1} ,sw2 = {-1, -1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (abs(x - 2 * (a[i] - b[j])) < result) {
                result = abs(x - 2 * (a[i] - b[j]));
                sw1 = {i+1, j+1};
            }
        }
    }
    ll y = x / 2;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    for (auto [t, q]: vb) {
        auto ita = upper_bound(va.begin(), va.end(), make_pair(y + t, make_pair(n, m)));
        if (ita != va.end()) {
            auto [s, p] = *ita;
            if (abs(x - 2 * (s - t)) < result) {
                result = abs(x - 2 * (s - t));
                sw1 = {p.first, q.first};
                sw2 = {p.second, q.second};
            }
        }
        if (ita != va.begin()) {
            auto [s, p] = *(--ita);
            if (abs(x - 2 * (s - t)) < result) {
                result = abs(x - 2 * (s - t));
                sw1 = {p.first, q.first};
                sw2 = {p.second, q.second};
            }
        }
    }
    cout << result << '\n';
    if (swapped) {
        swap(sw1.first, sw1.second);
        swap(sw2.first, sw2.second);
    }
    if (sw2 != make_pair(-1, -1)) {
        cout << 2 << '\n';
        cout << sw1.first << ' ' << sw1.second << '\n';
        cout << sw2.first << ' ' << sw2.second << '\n';
    } else if (sw1 != make_pair(-1, -1)) {
        cout << 1 << '\n';
        cout << sw1.first << ' ' << sw1.second << '\n';
    } else {
        cout << 0 << '\n';
    }
}