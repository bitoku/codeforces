#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod = 1000000007;

vector<bool> make_primes(int n) {
    vector<bool> v(n+1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * 2 <= n; ++i) {
        v[2 * i] = false;
    }
    for (int i = 3; i < n; ++i) {
        if (!v[i]) continue;
        for (int j = 2; j * i <= n; ++j) {
            v[j * i] = false;
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll n;
    cin >> n;
    vector<bool> p = make_primes(2000000);
    vector<ll> a(n);
    int one = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) one++;
    }
    if (one >= 2) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 1) continue;
            if (!p[a[i] + 1]) continue;
            cout << one + 1 << endl;
            for (int j = 0; j < one; ++j) {
                cout << 1 << ' ';
            }
            cout << a[i] << endl;
            return 0;
        }
        cout << one << endl;
        for (int j = 0; j < one; ++j) {
            cout << 1 << ' ';
        }
        cout << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (p[a[i] + a[j]]) {
                cout << 2 << endl;
                cout << a[i] << ' ' << a[j] << endl;
                return 0;
            }
        }
    }
    cout << 1 << endl;
    cout << a[0] << endl;
}