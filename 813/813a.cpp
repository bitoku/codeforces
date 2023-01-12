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
    int s = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s += x;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (l <= s && s <= r) {
            cout << s << endl;
            return 0;
        }
        if (l > s) {
            cout << l << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}