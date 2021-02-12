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
        vector<int> b(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }
        int amin = *min_element(a.begin(), a.end());
        int bmin = *min_element(b.begin(), b.end());
        ll cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += max(a[j] - amin, b[j] - bmin);
        }
        cout << cnt << endl;
    }
}
