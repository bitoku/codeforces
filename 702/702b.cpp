#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll m = a.back();
    ll result = 0;
    for (ll i = 2; i <= m * 2; i <<= 1) {
        for (int j = 0; j < n; ++j) {
            if (i - a[j] < a[j]) continue;
            if (i - a[j] == a[j]) {
                auto it = lower_bound(a.begin(), a.end(), a[j]);
                auto itr = upper_bound(a.begin(), a.end(), a[j]);
                ll d = distance(it, itr);
                result += d * (d - 1) / 2;
                break;
            }
            auto it = lower_bound(a.begin(), a.end(), i - a[j]);
            auto itr = upper_bound(a.begin(), a.end(), i - a[j]);
            result += distance(it, itr);
        }
    }
    cout << result << endl;
}