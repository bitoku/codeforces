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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<pair<int, int>> mini(n), maxi(n);
    vector<int> k;
    for (int i = 0; i < n; ++i) {
        while (!k.empty() && a[k.back()] > a[i]) {
            int j = k.back();
            k.pop_back();
            mini[j].second = i;
        }
        if (k.empty()) {
            mini[i].first = 0;
        } else {
            mini[i].first = k.back() + 1;
        }
        k.push_back(i);
    }
    while (!k.empty()) {
        mini[k.back()].second = n;
        k.pop_back();
    }
//    for (int i = 0; i < n; ++i) {
//        cout << mini[i].first << ' ' << mini[i].second << endl;
//    }

    for (int i = 0; i < n; ++i) {
        while (!k.empty() && a[k.back()] < a[i]) {
            int j = k.back();
            k.pop_back();
            maxi[j].second = i;
        }
        if (k.empty()) {
            maxi[i].first = 0;
        } else {
            maxi[i].first = k.back() + 1;
        }
        k.push_back(i);
    }
    while (!k.empty()) {
        maxi[k.back()].second = n;
        k.pop_back();
    }
//    for (int i = 0; i < n; ++i) {
//        cout << maxi[i].first << ' ' << maxi[i].second << endl;
//    }
    ll result = 0;
    for (int i = 0; i < n; ++i) {
        result += (ll)(i - maxi[i].first + 1) * (maxi[i].second - i) * a[i];
    }
    for (int i = 0; i < n; ++i) {
        result -= (ll)(i - mini[i].first + 1) * (mini[i].second - i) * a[i];
    }
    cout << result << endl;
}