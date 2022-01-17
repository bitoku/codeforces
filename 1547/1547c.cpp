#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int _ = 0; _ < t; ++_) {
        ll k, n, m;
        cin >> k >> n >> m;
        deque<ll> a(n);
        deque<ll> b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        vector<ll> result;
        for (int i = 0; i < n + m; ++i) {
            if (!a.empty() && k >= a.front()) {
                if (a.front() == 0) k++;
                result.push_back(a.front());
                a.pop_front();
            } else if (!b.empty() && k >= b.front()) {
                if (b.front() == 0) k++;
                result.push_back(b.front());
                b.pop_front();
            } else {
                break;
            }
        }
        if (result.size() == n + m) {
            cout << result[0];
            for (int i = 1; i < n + m; ++i) {
                cout << ' ' << result[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}