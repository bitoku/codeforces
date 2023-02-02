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
    map<ll, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    if (a[0] == a[1] && a[1] == a[2]) {
        ll x = cnt[a[0]];
        cout << x * (x - 1) * (x - 2) / 6 << endl;
        return 0;
    } else if (a[0] == a[1]) {
        ll x = cnt[a[0]];
        ll y = cnt[a[2]];
        cout << x * (x - 1) / 2 * y << endl;
        return 0;
    } else if (a[1] == a[2]) {
        ll x = cnt[a[0]];
        ll y = cnt[a[1]];
        cout << x * y * (y-1) / 2 << endl;
    } else {
        ll x = cnt[a[0]];
        ll y = cnt[a[1]];
        ll z = cnt[a[2]];
        cout << x * y * z << endl;
    }
}