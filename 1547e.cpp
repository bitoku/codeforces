#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll q;
    cin >> q;
    for (int _ = 0; _ < q; ++_) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(k);
        vector<ll> t(k);
        map<ll, int> r;
        for (int i = 0; i < k; ++i) {
            cin >> a[i];
            a[i]--;
            r[a[i]] = i;
        }
        for (int i = 0; i < k; ++i) {
            cin >> t[i];
        }
        multiset<ll> left, right;
        for (int i = 0; i < k; ++i) {
            right.insert(t[i] + a[i]);
        }
        vector<ll> result(n);
        for (int i = 0; i < n; ++i) {
            if (r.find(i) != r.end()) {
                int j = r[i];
                auto it = right.find(t[j] + a[j]);
                right.erase(it);
                left.insert(t[j] - a[j]);
            }
            if (left.empty()) {
                result[i] = *right.begin() - i;
            } else if (right.empty()) {
                result[i] = *left.begin() + i;
            } else {
                result[i] = min(*left.begin() + i, *right.begin() - i);
            }
        }
        cout << result[0];
        for (int i = 1; i < n; ++i) {
            cout << ' ' << result[i];
        }
        cout << endl;
    }
}