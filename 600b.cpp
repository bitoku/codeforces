#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> result;
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        auto it = upper_bound(a.begin(), a.end(), b[i]);
        result.push_back(distance(a.begin(), it));
    }
    cout << result[0];
    for (int i = 1; i < m; ++i) {
        cout << ' ' << result[i];
    }
    cout << endl;
}