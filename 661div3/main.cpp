#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        sort(a.begin(), a.end());
        int prev = a[0];
        bool ok = true;
        for (int j = 1; j < n; ++j) {
            if (a[j] - prev > 1) {
                ok = false;
                break;
            }
            prev = a[j];
        }
        if (ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
