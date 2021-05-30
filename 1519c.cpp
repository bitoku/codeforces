#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    ll t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        ll n;
        cin >> n;
        map<ll, vector<ll>> m;
        vector<int> univ(n);
        for (int j = 0; j < n; ++j) {
            cin >> univ[j];
            univ[j]--;
        }
        for (int j = 0; j < n; ++j) {
            ll s;
            cin >> s;
            m[univ[j]].push_back(s);
        }
        for (auto& [k, v]: m) {
            sort(v.begin(), v.end(), greater<>());
            for (int j = 1; j < v.size(); ++j) {
                v[j] += v[j-1];
            }

        }
        for (int k = 1; k <= n; ++k) {
            ll result = 0;
            for (auto it = m.begin(); it != m.end();) {
                if (it->second.size() < k) {
                    it = m.erase(it);
                    continue;
                }
                result += it->second[it->second.size() / k * k - 1];
                it++;
            }
            cout << result << ' ';
        }
        cout << endl;
    }

}