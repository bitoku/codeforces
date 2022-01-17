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
        vector<ll> a(n);
        bool inorder = true;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
            if (a[j] != j + 1) inorder = false;
        }
        if (inorder) {
            cout << 0 << endl;
        } else {
            if (a[0] == n && a[n-1] == 1) {
                cout << 3 << endl;
            } else if (a[0] == 1 || a[n-1] == n) {
                cout << 1 << endl;
            } else {
                cout << 2 << endl;
            }
        }
    }
}